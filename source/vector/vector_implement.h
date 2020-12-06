/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-06 18:55:58
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include "vector/vector.h"
#include <iostream>
using namespace std;

template <typename T>
Vector<T>::Vector(int c, int s, T v)
{
    _elem = new T[_capacity = c];
    for (_size = 0; _size < s; _elem[_size++] = v)
        ;
};

template <typename T>
void Vector<T>::copyfrom(T const *A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi)
    {
        _elem[_size++] = A[lo++];
    }
}

template <typename T>
Vector<T>::Vector(T const *A, Rank lo, Rank hi)
{
    copyfrom(A, lo, hi);
};

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &V)
{
    if (_elem)
        delete[] _elem;
    copyfrom(V._elem, 0, V.size());
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] _elem;
}

// 遍历
template <typename T>
void Vector<T>::traverse(void (*visit)(T &)) const
{
    for (int i = 0; i < _size; i++)
    {
        visit(_elem[i]);
    }
    cout << "    ; The final size is : " << _size << "  and capacity is : " << _capacity << endl;
};

// 扩充
template <typename T>
void Vector<T>::expand()
{
    if (_size < _capacity)
        return;
    if (_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;
    T *_old_elem = _elem;
    _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = _old_elem[i];
    }
    delete[] _old_elem;
};

// 插入
template <typename T>
void Vector<T>::insert(Rank r, const T &elem)
{
    if (r > _size)
    {
        cerr << "insert error :r must be less than _size" << endl;
        return;
    }

    expand();
    for (int i = _size; i > r; i--)
    {
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = elem;
    _size++;
};

// 删除
template <typename T>
// remove [lo,hi)
int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
        return 0;
    while (hi < _size)
    {
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    // shrink,若有必要，缩小规模
    return hi - lo;
};

template <typename T>
// remove [r]
T Vector<T>::remove(Rank r)
{
    if (r < 0 || _size <= r)
    {
        cerr << "empty ,nothing can be removed" << endl;
        T data;
        return data;
    }
    T e = _elem[r];
    remove(r, r + 1);
    return e;
}

template <typename T>
T &Vector<T>::operator[](Rank r)
{
    return _elem[r];
};

template <typename T>
const T &Vector<T>::operator[](Rank r) const
{
    return _elem[r];
};
// ---------------------------------无序向量---------------------------------------------

// 无序号向量查找 find[lo,hi)
template <typename T>
Rank Vector<T>::find(const T &e, Rank lo, Rank hi)
{
    while ((lo < hi--) && (e != _elem[hi]))
        ;      //逆向查找
    return hi; //hi<lo 意味查找失败
};

// 无序向量唯一化:去重
template <typename T>
int Vector<T>::deduplicate()
{
    int oldsize = _size;
    for (int i = 0; i < _size; i++)
    {
        ((find(_elem[i], 0, i)) < 0) ? 0 : remove(i);
    }
    return oldsize - _size;
};

// 无序向量唯一化:去重
template <typename T>
int Vector<T>::deduplicate_2()
{
    int oldsize = _size;
    for (int i = 0; i < _size; i++)
    {
        while (true)
        {
            int idx = find(_elem[i], i + 1, _size);
            if (idx < i + 1)
                break;
            remove(idx);
        }
    }
    return oldsize - _size;
};

// ---------------------------------有序向量---------------------------------------------

// 向量排序,有序化
#include "vector/sort.h"

// 有序向量查找 二分查找 (减而治之) e<x;e>x;e=x;

// 有序向量唯一化,时间复杂度为O(n)
template <typename T>
int Vector<T>::uniquify()
{
    int oldsize = _size;
    int i = 0, j = 0;
    while (++j < _size)
    {
        if (_elem[i] != _elem[j])
        {
            _elem[++i] = _elem[j];
        }
    }
    _size = ++i;
    return j - i;
}

template <typename T>
Rank Vector<T>::search(const T &e, Rank lo, Rank hi, SEARCHING kind)
{
    switch (kind)
    {
    case BINSEARCH:
    {
        Rank r = binsearch_3(_elem, e, lo, hi);
        return r;
    }
    default:
        return -1;
    }
}

template <typename T>
Rank Vector<T>::binsearch(const T *A, const T &e, Rank lo, Rank hi)
{
    if (lo < hi)
    {
        Rank mid = (lo + hi) / 2, idx = mid;
        if (e < A[mid])
            idx = binsearch(A, e, lo, mid - 1);
        else if (e > A[mid])
            idx = binsearch(A, e, mid + 1, hi);
        return idx;
    }
    return -1;
}

// 二分查找的迭代版本
template <typename T>
Rank Vector<T>::binsearch_2(const T *A, const T &e, Rank lo, Rank hi)
{
    while (lo < hi)
    {
        Rank mid = (lo + hi) / 2;
        if (e < A[mid])
            hi = mid - 1;
        else if (e > A[mid])
            lo = mid + 1;
        else
            return mid;
    }
    return -1;
}

// 二分查找的迭代版本:最好版本。
// 当有多个命中时只返回秩最大者，若无命中时返回小于e的最大者
// 算法核心:不变性 A[lo,mid)<=e and A[hi,n)>e
template <typename T>
Rank Vector<T>::binsearch_3(const T *A, const T &e, Rank lo, Rank hi)
{
    while (lo < hi)
    {
        Rank mid = (lo + hi) >> 1;
        (e < A[mid]) ? hi = mid : lo = mid + 1; //[lo,mid) or (mid,hi)
    }
    return --lo;
}