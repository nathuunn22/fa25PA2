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

    void push(int const idx, int const weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int const weightArr[]) {
        // TODO: remove and return smallest index
        int const temp = data[0];
        data[0] = data[size - 1];
        size--;
        // Replace root with last element, then call downheap()
        downheap(0, weightArr);
        return temp; // placeholder
    }

    void upheap(int pos, int const weightArr[]) {
        // TODO: swap child upward while smaller than parent
        if (size <= 1) {
            return;
        }

        int parentPos = (pos-1)/2;
        while (weightArr[data[parentPos]] > weightArr[data[pos]] && parentPos > 0) {
            swap(parentPos, pos);
            pos = parentPos;
            parentPos = (pos-1)/2;
        }
    }

    void downheap(int pos, int const weightArr[]) {
        // TODO: swap parent downward while larger than any child
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

    void swap(const int x, const int y) {
        int const temp = data[x];
        data[x] = data[y];
        data[y] = temp;
    }


    void print(int charArr[]) {
        for (int i = 0; i < size; i++) {
            cout << charArr[data[i]] << " ";
        }
        cout << endl;
    }
};

#endif