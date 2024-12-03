#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include "swap.h"
void max_heap_insert(int value, int array[], int& size);
void max_heap_sift_down(int array[], int& size);
void max_heap_sift_down(int array[], int left, int right);
void heap_sort(int array[], int size);
void heapSortRemove(int arr[], int size);
int heap_remove(int array[], int& size);
void make_max_heap_top_down(int array[], int size);
void make_max_heap_bottom_up(int array[], int size);


int parent(int index) {
    return (index - 1) / 2;
}

int leftChild(int index) {
    return 2 * index + 1;
}

int rightChild(int index) {
    return 2 * index + 2;
}

void max_heap_sift_down(int array[], int& size) {
    max_heap_sift_down(array, 0, size-1);
}

void max_heap_sift_down(int array[], int left, int right) {
    bool done = false;
    int currIdx = left;
    while( !done && leftChild(currIdx) <= right) {
        int maxIdx = leftChild(currIdx);
        if(rightChild(currIdx) <= right && 
           array[rightChild(currIdx)] > array[maxIdx]) {
            
            maxIdx = rightChild(currIdx);
        }

        if(array[maxIdx] > array[currIdx]) {
            swap(&(array[currIdx]), &(array[maxIdx]));
            currIdx = maxIdx;
        } else {
            done = true;
        }
    }
}

void heap_sort(int array[], int size) {
    make_max_heap_bottom_up(array, size);
    heapSortRemove(array, size);
}

void heapSortRemove(int arr[], int size) {
    int currSize = size;
    for(int i = 0; i < size; i++) {
        heap_remove(arr, currSize);
    }
}

void max_heap_insert(int value, int array[], int& size) {
    int currIdx = size;
    array[currIdx] = value;
    while( currIdx > 0 && array[currIdx] > array[parent(currIdx)]) {
        swap(&(array[currIdx]), &(array[parent(currIdx)]));
        currIdx = parent(currIdx);
    }
    size++;
}

int heap_remove(int array[], int& size) {
    int retVal = array[0];
    swap(&(array[0]), &(array[size-1]));
    size--;

    max_heap_sift_down(array, size);
    return retVal;
}

void make_max_heap_top_down(int array[], int size) {
    int currSize = 0;
    while( currSize < size)
        max_heap_insert(array[currSize], array, currSize);
}

void make_max_heap_bottom_up(int array[], int size) {
    int currIdx = parent(size - 1);
    while(currIdx >= 0) {
        max_heap_sift_down(array, currIdx, size - 1);
        currIdx--;
    }
}

#endif
