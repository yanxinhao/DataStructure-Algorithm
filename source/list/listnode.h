/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-03 21:07:11
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include "list/list.h"
#include <iostream>
#define Posi(T) ListNode<T> *
// 单向链表节点
template <typename T>
struct LNode
{
    T data;
    LNode<T> *next;
    LNode() { next = NULL; }
    LNode(T e) : data(e), next(NULL){};
};

// 双向链表节点
template <typename T>
struct ListNode
{
    T data;
    Posi(T) pred;
    Posi(T) succ;
    ListNode(){};
    ~ListNode(){};
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