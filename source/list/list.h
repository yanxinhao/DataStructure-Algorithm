/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-13 21:17:59
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include<iostream>
#include"list/listnode.h"
using namespace std;

enum SORTING{
    SELECTIONSORT,
    INSERTIONSORT,
    MERGESORT
};

template<typename T>
class list
{
private:
    int _size;
    void init();
    Posi(T) header;
    Posi(T) trailer;
public:
    list(/* args */);
    list(const T* array,int len);
    ~list();

    void traverse(void (*visit)(T&));

    // 唯一化

    // 排序
    bool sort(Posi(T) p,int n,SORTING kind=SELECTIONSORT);
    // 选择排序
    bool selectionsort(Posi(T) p,int n);
    // 插入排序
    bool insertionsort(Posi(T) p,int n);
    // 归并排序
    bool mergesort(Posi(T) p ,int n);
};


#include "list/list_implement.h"