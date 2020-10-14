/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-13 21:30:19
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include "list/list.h"

template <typename T>
void list<T>::init()
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = NULL;
    trailer->pred = header;
    trailer->succ = NULL;
    _size = 0;
}

template <typename T>
list<T>::list(/* args */)
{
    init();
}

template <typename T>
list<T>::list(const T *array, int len)
{
    init();
    Posi(T) p = header;
    for (int i = 0; i < len; i++)
    {
        p->insertAsSucc(array[i]);
        p = p->succ;
        _size++;
    }
}

template <typename T>
list<T>::~list()
{
    Posi(T) p = trailer->pred;
    while ((p = p->pred) != header)
    {
        delete p;
        _size--;
    }
}

template <typename T>
void list<T>::traverse(void (*visit)(T &))
{
    Posi(T) p = header;
    while ((p = p->succ) != trailer)
    {
        visit(p->data);
    }
    cout << endl;
}

// sorting
template <typename T>
bool list<T>::sort(Posi(T) p, int n, SORTING kind)
{
    bool sorted = false;
    switch (kind)
    {
    case SELECTIONSORT:
    {
        sorted = selectionsort(p, n);
        break;
    }
    case INSERTIONSORT:
    {
        sorted = insertionsort(p, n);
        break;
    }
    case MERGESORT:
    {
        sorted = mergesort(p, n);
        break;
    }
    default:
        break;
    }
    return sorted;
}

template <typename T>
bool list<T>::selectionsort(Posi(T) p, int n)
{
    return true;
}

template <typename T>
bool list<T>::insertionsort(Posi(T) p, int n)
{
    return true;
}

template <typename T>
bool list<T>::mergesort(Posi(T) p, int n)
{
    return true;
}
