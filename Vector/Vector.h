//
// Created by HP on 9/16/2024.
//

#ifndef UNTITLED2_VECTOR_H
#define UNTITLED2_VECTOR_H
#include <iostream>
using namespace std;
template<class T>

class Vector {
private:
    T *arr = nullptr;
    int size = 0 ;
    int maxSize ;
public:
    Vector();
    Vector(int maxSize);
    T get(int indx);
    void set(int indx , T val);
    void print();
    T front();
    T back();
    void rotateRight(int val);
    void push_back(T val);
    void inCapacity();
    void insert(int indx , T val);
    void rotateRight();
    void rotateLeft();
    T operator[](int i );
    T find(T val);
    ~Vector();
};


#endif //UNTITLED2_VECTOR_H

template<class T>
Vector<T> ::Vector() {
    size = 0;
    maxSize = 200;
    arr = new T[maxSize];
}
template<class T>
Vector<T> ::Vector(int maxSize) {
    size = 0;
    this -> maxSize = maxSize;
    if(maxSize < 0)maxSize = 1;
    arr = new T[maxSize];
}
template<class T>
T Vector<T>::get(int indx) {
    if(indx < 0 or indx >= size){
        throw out_of_range("index not found");
    }
    return arr[indx];
}
template<class T>
void Vector<T>::set(int indx, T val) {
    if(indx < 0 or indx > size){
        return ;
    }
    if(size == maxSize)inCapacity();
    if(indx == size)size++;
    arr[indx] = val ;
}
template<class T>
T Vector<T>::front() {
    if(size > 0)return arr[0];
    throw out_of_range("Empty");
}
template<class T>
T Vector<T>::back() {
    if(size > 0)return arr[size - 1];
    throw out_of_range("Empty");
}
template<class T>
void Vector<T>::push_back(T val) {
    if(size < maxSize){
        arr[size++] = val;
        return ;
    }
    cout << "Fully\n";
    inCapacity();
    arr[size++] = val;
}
template<class T>
void Vector<T>::insert(int indx, T val) { //O(n)
    if(indx < 0 or indx > size)return;
    if(size == maxSize)inCapacity();
    for(int i = size ; i > indx ; --i){
        arr[i] = arr[i - 1];
    }
    arr[indx] = val;
    size++;
}
template<class T>
void Vector<T>::inCapacity() {
    T *arr2 = (new T[maxSize * 2]);
    for(int i = 0 ; i < size ; ++i) {
        arr2[i] = arr[i];
    }
    maxSize *= 2;
    swap(arr2 , arr);
    delete [] arr2;
}
template<class T>
void Vector<T>::print() {
    for(int i = 0 ; i < size ; ++i){
        cout << arr[i] << " ";
    }
    cout << '\n';
}

template<class T>
void Vector<T>::rotateRight() {
    if(size < 2)return;
    int k = arr[size - 1];
    for(int i = size - 1 ; i > 0 ; --i){
        arr[i] = arr[i - 1];
    }
    arr[0] = k;
}

template<class T>
void Vector<T>::rotateRight(int val) {
    if(size < 2)return;
    if(val == 1){
        rotateRight();
        return;
    }
    int * arr1 = new T[maxSize];
    for(int i = 0 ; i < size ; ++i){
        arr1[(i + val) % size] = arr[i];
    }
    swap(arr, arr1);
    delete [] arr1;
}

template<class T>
void Vector<T>::rotateLeft() {
    if(size < 2)return;
    int k = arr[0];
    for(int i = 0 ; i < size - 1 ; ++i){
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = k;
}

template<class T>
T Vector<T>::find(T val) {
    for(int i = 0 ; i < size ; ++i){
        if(arr[i] == val)return i;
    }
    throw out_of_range("Not Found");
}
template<class T>
T Vector<T>::operator[](int i) {
    if(i < 0 or i >= size)return -1;
    return arr[i];
}
template<class T>
Vector<T> ::~Vector() {
    delete [] arr;
    arr = nullptr;
}
