/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-11-19 23:08:38
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include "list/listnode.h"
#include <iostream>
using namespace std;

enum SORTING
{
    SELECTIONSORT,
    INSERTIONSORT,
    MERGESORT
};

template <typename T>
class list
{
private:
    int _size;
    void init();
    Posi(T) header;
    Posi(T) trailer;

public:
    list(/* args */);
    list(const T *array, int len);
    ~list();
    int size() { return _size; }
    Posi(T) first() { return header->succ; }
    Posi(T) insertB(Posi(T) p, const T &e);
    T remove(Posi(T) p);
    void traverse(void (*visit)(T &));

    // 唯一化

    // 排序
    bool sort(SORTING kind = SELECTIONSORT);
    // 选择排序
    bool selectionsort(Posi(T) p, int n);
    // 插入排序
    bool insertionsort(Posi(T) p, int n);
    // 归并排序
    Posi(T) merge(Posi(T) L, int m, Posi(T) R, int n);
    bool mergesort(Posi(T) & p, int n);
};

#include "list/list_implement.h"