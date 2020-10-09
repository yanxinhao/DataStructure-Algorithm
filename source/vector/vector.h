/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-09 23:16:15
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once

typedef int Rank;
#define DEFAULT_CAPACITY 100

#include <iostream>

template <typename T>
class Vector
{
private:
    Rank _size;
    int _capacity;
    T* _elem;
    void copyfrom(T const * A,Rank lo,Rank hi);
    void expand();
public:
    Vector(int c = DEFAULT_CAPACITY);
    Vector(T const * A,Rank lo,Rank hi);

    void insert(Rank r,const T& elem);
    int remove(Rank lo,Rank hi);
    void traverse(void (*visit)(T&)) const;
    ~Vector();
};

#include"vector/vector_implement.h"