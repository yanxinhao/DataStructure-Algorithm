/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-06 21:06:20
 * @LastEditors: yanxinhao
 * @Description: 完全二叉堆的实现
 */
#pragma once
#include "binheap/compl_heap.h"

template <typename T>
ComplHeap<T>::ComplHeap(Vector<T> v)
{
    data = heapify(v);
    _size = data.size();
}

template <typename T>
ComplHeap<T>::~ComplHeap()
{
}

template <typename T>
Vector<T> ComplHeap<T>::heapify(Vector<T> &v)
{
    int size = v.size();
    int s = (size / 2) - 1; //初始第一个下滤的节点，因为数组从0开始，所以要减一
    for (; 0 <= s; s--)
        percolate_down(s, v, v.size());
    return v;
};

/**
 * @brief 从当前节点和其孩子(如果存在)中选择一个合适的作为父亲节点，判断依据是大根堆或者小根堆的性质
 * 
 * @tparam T 
 * @param i 
 * @param v 
 * @return Rank 
 */
template <typename T>
Rank ComplHeap<T>::properparent_max(Rank i, Vector<T> &v, int n)
{
    int out = i;
    int l = lchild(i, n);
    int r = rchild(i, n);
    if (l != -1 && v[i] < v[l])
        out = l;
    if (r != -1 && v[out] < v[r])
        out = r;
    return out;
};

template <typename T>
void ComplHeap<T>::percolate_up(Rank i)
{
    while (parent(i) != -1)
    {
        if (data[i] < data[parent(i)])
            break;
        swap(data[parent(i)], data[i]);
        i = parent(i);
    }
};

template <typename T>
void ComplHeap<T>::percolate_down(Rank i, Vector<T> &v, int n)
{
    Rank p;
    while (i != (p = properparent_max(i, v, n)))
    {
        swap(v[p], v[i]);
        i = p;
    }
};

template <typename T>
void ComplHeap<T>::heapsort(Vector<T> &v)
{
    v = heapify(v);
    for (int i = 0; i < v.size(); i++)
    {
        swap(v[0], v[v.size() - 1 - i]);
        percolate_down(0, v, v.size() - 1 - i);
    }
};

template <typename T>
void ComplHeap<T>::traverse(void (*visit)(T &))
{
    for (int i = 0; i < _size; i++)
    {
        visit(data[i]);
    }
};

template <typename T>
T &ComplHeap<T>::delmax()
{
    if (data.empty())
        cerr << "heap is empty" << endl;
    int last = data.size() - 1;
    T max_ = data[0];
    data[0] = data[last];
    data.remove(last);
    percolate_down(0, data, data.size());
    return max_;
};

template <typename T>
void ComplHeap<T>::insert(const T &elem)
{
    data.insert(elem);
    _size = data.size();
    percolate_up(data.size() - 1);
};