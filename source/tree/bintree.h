/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-05 12:34:48
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include "tree/binnode.h"

#define stature(p) ((p) ? (p)->height : -1) //节点高度，约定空树的高度为-1

enum TRAVERSETYPE
{
    PREORDER,
    INORDER,
    POSTORDER,
    PREORDERNOCURSION,
    INORDERNOCURSION,
    POSTORDERNOCURSION
};
template <typename T>
/**
 * @brief 只有双亲节点指针的一般二叉树
 * 
 */
class bintree
{
private:
    Node<T> *_root;

public:
    bintree(/* args */);
    bintree(int len, const T *p_order, const T *in_order);          //利用先序和中序序列建立二叉树
    Node<T> *restore(int len, const T *p_order, const T *in_order); //利用先序和中序序列建立二叉树,递归函数
    ~bintree();
    // 遍历
    void traverse(void (*visit)(T &), TRAVERSETYPE type);
    void preorder(Node<T> *p, void (*visit)(T &));
    void inorder(Node<T> *p, void (*visit)(T &));
    void postorder(Node<T> *p, void (*visit)(T &));
    void preorder_nocursion(Node<T> *p, void (*visit)(T &));
    void inorder_nocursion(Node<T> *p, void (*visit)(T &));
    void postorder_nocursion(Node<T> *p, void (*visit)(T &));
};

template <typename T>
/**
 * @description: 既有双亲孩子节点指针，也有父节点指针的二叉树
 * @param {*}
 * @return {*}
 */
class BinTree
{
private:
    int _size;
    BinNodePosi(T) _root;
    void createbintree(BinNodePosi(T) subtree, const T *A, int i, int n);
    virtual int updateHeight(BinNodePosi(T) x); //更新节点x的高度
    void updateHeightAbove(BinNodePosi(T) x);

public:
    int size() const { return _size; };
    bool empty() const { return !_root; };
    BinNodePosi(T) root() const { return _root; }
    BinTree(/* args */);
    BinTree(const T *A, int n);
    ~BinTree();

    BinNodePosi(T) insertAsRc(BinNodePosi(T) x, const T &e);
    BinNodePosi(T) insertAsLc(BinNodePosi(T) x, const T &e);

    // 前序遍历
    // 中序遍历
    // 后序遍历

    // 利用先序和中序序列建立二叉树
    void restore();
    BinNodePosi(T) restore(const char *ppos, const char *ipos, int n);
};

#include "tree/bintree_implement.h"
#include "tree/standard_bintree_implement.h"