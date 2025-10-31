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

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        if (size <= 1) {
            return;
        }

        int parentPos = (pos-1)/2;
        while (weightArr[data[parentPos]] > weightArr[data[pos]] && parentPos > 0) {
            int temp = data[parentPos];
            data[parentPos] = data[pos];
            data[pos] = temp;
            pos = parentPos;
            parentPos = (pos-1)/2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }

    void print(char charArr[]) {
        for (int i = 0; i < size; i++) {
            cout << charArr[data[i]] << " ";
        }
        cout << endl;
    }
};

#endif