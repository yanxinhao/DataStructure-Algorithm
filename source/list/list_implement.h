/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-11-20 00:21:54
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
Posi(T) list<T>::insertB(Posi(T) p, const T &e)
{
    _size++;
    return p->insertAsPred(e);
};

template <typename T>
T list<T>::remove(Posi(T) p)
{
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    T temp = p->data;
    delete p;
    _size--;
    return temp;
};

template <typename T>
void list<T>::traverse(void (*visit)(T &))
{
    Posi(T) p = header;
    while ((p = p->succ) != trailer)
    {
        visit(p->data);
    }
    cout << endl;
};

//单链表逆置
template <typename T>
Posi(T) list<T>::divide_reverse(Posi(T) start)
{
    if (start == NULL || start->succ == NULL)

        return start;
    else
    {
        Posi(T) newhead = divide_reverse(start->succ);
        start->succ->succ = start;
        start->succ = NULL;
        return newhead;
    }
};

// 双链表逆置
template <typename T>
void list<T>::reverse()
{
    Posi(T) p = header;
    while (p)
    {
        Posi(T) temp = p->succ;
        p->succ = p->pred;
        p->pred = temp;
        p = temp;
    }
    Posi(T) t = header;
    header = trailer;
    trailer = t;
};

// sorting
template <typename T>
bool list<T>::sort(SORTING kind)
{
    Posi(T) p = first();
    bool sorted = false;
    switch (kind)
    {
    case SELECTIONSORT:
    {
        sorted = selectionsort(p, size());
        break;
    }
    case INSERTIONSORT:
    {
        sorted = insertionsort(p, size());
        break;
    }
    case MERGESORT:
    {
        sorted = mergesort(p, size());
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
Posi(T) list<T>::merge(Posi(T) L, int m, Posi(T) R, int n)
{
    Posi(T) pp = L->pred;       //记录[L,R]的前一个节点，方便返回合并后的起始节点
    while ((0 < n) && (L != R)) //R仍然还有剩余且L与R没有相遇
    {
        if (0 < m && (L->data <= R->data))
        {
            m--;
            if (R == (L = L->succ))
                break;
        }
        else //(R->data) < (L->data)或者L已经遍历完现已出界
        {
            n--;
            Posi(T) s = R->succ;
            insertB(L, remove(R));
            R = s;
            // insertB(L, remove((R = R->succ)->pred));//因为有尾节点所以可以这么写
        }
    }
    return pp->succ;
}

template <typename T>
bool list<T>::mergesort(Posi(T) & p, int n) //对起始于p的n个元素排序
{
    if (n < 2)
        return true;
    Posi(T) p_mid = p;
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
        p_mid = p_mid->succ;
    mergesort(p, mid); //左半部分不包含mid节点，但是其长度为mid
    mergesort(p_mid, n - mid);
    p = merge(p, mid, p_mid, n - mid);
    return true;
}
