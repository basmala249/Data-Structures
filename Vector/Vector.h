//
// Created by HP on 9/16/2024.
//

#ifndef UNTITLED2_VECTOR_H
#define UNTITLED2_VECTOR_H

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
    void push_back(T val);
    void inCapacity();
    void insert(int indx , T val);
    T& operator[](int i );
    T find(T val);
    ~Vector();
};


#endif //UNTITLED2_VECTOR_H
