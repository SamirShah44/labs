#ifndef SWAP_H_
#define SWAP_H_

template<class T>
void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

#endif