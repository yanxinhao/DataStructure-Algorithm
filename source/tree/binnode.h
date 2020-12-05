/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-05 10:59:56
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include <iostream>
#define BinNodePosi(T) BinNode<T> *

template <typename T>
/**
 * @description: 只含双亲节点指针
 * @param {*}
 * @return {*}
 */
struct Node
{
    T data;
    Node<T> *lchild, *rchild;
    Node() : lchild(NULL), rchild(NULL){};
    Node(const T &e) : data(e), lchild(NULL), rchild(NULL){};
    ~Node(){};
};

template <typename T>
/**
 * @description: 既带双亲节点指针，也带父节点指针
 * @param {*}
 * @return {*}
 */
struct BinNode
{
    BinNodePosi(T) parent, lchild, rchild;
    T data;
    int height;
    BinNode(const T &e, BinNodePosi(T) p = NULL, BinNodePosi(T) l = NULL, BinNodePosi(T) r = NULL, int h = 0) : data(e), parent(p), lchild(l), rchild(r), height(h){};
    int size(); //
    BinNodePosi(T) insertAsLc(const T &e);
    BinNodePosi(T) insertAsRc(const T &e);
};

template <typename T>
int BinNode<T>::size()
{
    int s = 1; //计入本身
    if (lchild)
        s += lchild->size();
    if (rchild)
        s += rchild->size();
    return s;
}

/**
 * @brief 插入节点作为当前节点的左孩子
 * 
 * @tparam T 
 */
template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLc(const T &e)
{
    lchild = new BinNode(e, this);
}

/**
 * @brief 插入节点作为当前节点的右孩子
 * 
 * @tparam T 
 */
template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRc(const T &e)
{
    rchild = new BinNode(e, this);
}