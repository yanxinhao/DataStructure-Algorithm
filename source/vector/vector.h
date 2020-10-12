/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-13 00:00:09
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once

typedef int Rank;
#define DEFAULT_CAPACITY 100

#include <iostream>

enum SORTING {
    BUBBLESORT

};

enum SEARCHING{
    BINSEARCH
};

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
    T remove(Rank r);
    void traverse(void (*visit)(T&)) const;
    Rank size(){return _size;};
    
    // 无序向量
    Rank find(const T& e,Rank lo,Rank hi);
    int deduplicate();
    int deduplicate_2();

    // 有序向量
    int uniquify();
    bool sort(Rank lo,Rank hi,SORTING kind = BUBBLESORT);
    ~Vector();
    Rank search(const T& e,Rank lo,Rank hi,SEARCHING kind=BINSEARCH);
    static Rank binsearch(const T* A,const T& e,Rank lo,Rank hi);
    static Rank binsearch_2(const T* A,const T& e,Rank lo,Rank hi);
    static Rank binsearch_3(const T* A,const T& e,Rank lo,Rank hi);
};

#include"vector/vector_implement.h"