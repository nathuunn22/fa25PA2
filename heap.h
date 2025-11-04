//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    //push element then upheap
    void push(int const idx, int const weightArr[]) {
        if (size >= 64) {
            return;
        }
        data[size] = idx;
        size++;
        upheap(size - 1, weightArr);
    }

    //pop element the downheap
    int pop(int const weightArr[]) {
        if (size == 0) {
            return -1;
        }
        int const temp = data[0];
        data[0] = data[size - 1];
        size--;
        downheap(0, weightArr);
        return temp;
    }


    void upheap(int pos, int const weightArr[]) {
        if (size <= 1) {
            return;
        }
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(pos, parent);
                pos = parent;
            } else {
                break;
            }
        }

    }

    void downheap(int pos, int const weightArr[]) {
        int leftChildPos = 2*pos+1;
        int rightChildPos = 2*pos+2;
        while (true) {
            if (pos >= size || leftChildPos >= size || rightChildPos >= size) {
                return;
            }

            if (weightArr[data[pos]] > weightArr[data[leftChildPos]]) {
                swap(leftChildPos, pos);
                pos = leftChildPos;
            } else if (weightArr[data[pos] > weightArr[data[rightChildPos]]]) {
                swap(rightChildPos, pos);
                pos = rightChildPos;
            }

            leftChildPos = 2*pos+1;
            rightChildPos = 2*pos+2;
        }

    }

    //helper swap function
    void swap(const int x, const int y) {
        int const temp = data[x];
        data[x] = data[y];
        data[y] = temp;
    }

};

#endif