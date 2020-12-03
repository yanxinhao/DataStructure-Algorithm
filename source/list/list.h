/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-03 23:16:47
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

//单向链表
template <typename T>
class linklist
{
private:
    int _size;
    LNode<T> *_header;
    void init()
    {
        _size = 0;
        _header = new LNode<T>;
    }
    /* data */
public:
    linklist(/* args */);
    linklist(const T *array, int len);
    ~linklist();

    int get_size() { return _size; }
    void traverse(void (*visit)(T &)); // 遍历
    void reverse();                    // 逆置
    LNode<T> *_reverse(LNode<T> *p);   // 逆置
    T ksearch_2009(int k);             //2009年真题，倒数第k个数
    void circle_move_2010(int p);      //2010年42题，循环左移p位
    void switch_2019();                //2019年真题
};

// 双向链表
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

    //逆置
    Posi(T) divide_reverse(Posi(T) start);
    void reverse();
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

#include "list/linklist_implement.h"
#include "list/list_implement.h"