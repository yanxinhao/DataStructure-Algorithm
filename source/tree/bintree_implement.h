/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-05 11:30:29
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include "stack/sqstack.h"
#include "tree/bintree.h"

template <typename T>
BinTree<T>::BinTree(/* args */)
{
}

template <typename T>
BinTree<T>::BinTree(const T *A, int n)
{
    BinNodePosi(T) address[n];
    if (n > 0)
    {
        _root = new BinNode<T>(A[0]);
        address[0] = _root;
    }

    for (int i = 1; i < n; i++)
    {
        // 按照列表顺序新建节点,并指定父节点
        BinNodePosi(T) father = address[i / 2];
        BinNodePosi(T) node = new BinNode<T>(A[i], father);
        address[i] = node; //记录节点的位置

        // 对于父节点来说,指定其孩子节点
        if (i % 2 == 0)
            father->lchild = node; //当前节点为father的左孩子
        else
            father->rchild = node; //当前节点为father的右孩子
    }
};

template <typename T>
void BinTree<T>::createbintree(BinNodePosi(T) subtree, const T *A, int i, int n)
{
}
/**
 * @brief Destroy the Bin Tree< T>:: Bin Tree object 以先序序列删除所有树节点
 * 
 * @tparam T 
 */
template <typename T>
BinTree<T>::~BinTree()
{
    sqstack<BinNodePosi(T)> s;
    s.push(_root);
    // 以先序序列删除所有树节点
    while (!s.empty())
    {
        Node<T> *p = s.pop();
        if (p->rchild)
            s.push(p->rchild);
        if (p->lchild)
            s.push(p->lchild);
        delete p;
    }
}

template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
    return x->height = 1 + max(stature(x->lchild), stature(x->rchild));
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
    while (x)
    {
        updateHeight(x);
        x = x->parent;
    }
};

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRc(BinNodePosi(T) x, const T &e)
{
    _size++;
    x->insertAsRc(e);
    updateHeightAbove(x);
    return x->rchild;
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLc(BinNodePosi(T) x, const T &e)
{
    _size++;
    x->insertAsLc(e);
    updateHeightAbove(x);
    return x->lchild;
}

template <typename T>
BinNodePosi(T) BinTree<T>::restore(const char *ppos, const char *ipos, int n){

};
template <typename T>
void BinTree<T>::restore()
{
}