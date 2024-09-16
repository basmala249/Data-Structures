//
// Created by HP on 9/16/2024.
//

#ifndef UNTITLED2_VECTOR_H
#define UNTITLED2_VECTOR_H


class Vector {
private:
    int *arr = nullptr;
    int size = 0 ;
public:
    Vector();
    Vector(int maxSize);
    int get(int indx);
    void set(int indx , int val);
    void print();
    int find(int val);
    ~Vector();
};


#endif //UNTITLED2_VECTOR_H
