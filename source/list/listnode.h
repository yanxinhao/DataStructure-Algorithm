/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-13 21:31:03
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include "list/list.h"
#include <iostream>
#define Posi(T) ListNode<T> *
template <typename T>
struct ListNode
{
    T data;
    Posi(T) pred;
    Posi(T) succ;
    ListNode(){};
    ListNode(T e, Posi(T) p = NULL, Posi(T) s = NULL) : data(e), pred(p), succ(s){};
    Posi(T) insertAsPred(const T &e);
    Posi(T) insertAsSucc(const T &e);
};

template <typename T>
Posi(T) ListNode<T>::insertAsPred(const T &e)
{
    Posi(T) node = new ListNode(e, pred, this);
    pred->succ = node;
    pred = node;
}

template <typename T>
Posi(T) ListNode<T>::insertAsSucc(const T &e)
{
    Posi(T) node = new ListNode(e, this, succ);
    succ->pred = node;
    succ = node;
}