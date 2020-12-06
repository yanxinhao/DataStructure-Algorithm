/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-05 14:02:22
 * @LastEditors: yanxinhao
 * @Description: 
 */

#pragma once
#include "stack/sqstack.h"
#include "tree/bintree.h"

/**
 * @brief 
 * 
 */
template <typename T>
bintree<T>::bintree(/* args */)
{
}
/**
 * @brief Construct a new bintree<T>::bintree object
 * 
 * @tparam T 
 * @param len 树的节点个数
 * @param p_order 前序遍历序列
 * @param in_order 中序遍历序列
 */
template <typename T>
bintree<T>::bintree(int len, const T *p_order, const T *in_order)
{
    _root = restore(len, p_order, in_order);
};

/**
 * @brief Destroy the bintree<T>::bintree object 以先序序列删除所有树节点
 * 
 * @tparam T 
 */
template <typename T>
bintree<T>::~bintree()
{
    sqstack<Node<T> *> s;
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

/**
 * @brief 递归函数，利用先序和中序序列建立二叉树
 * 
 * @tparam T 
 * @param len 树的节点个数
 * @param p_order 前序遍历序列
 * @param in_order 中序遍历序列
 */
template <typename T>
Node<T> *bintree<T>::restore(int len, const T *p_order, const T *in_order)
{
    if (len == 0)
        return NULL;
    Node<T> *root = new Node<T>(p_order[0]);

    // 在中序序列中查找根节点，根节点左右两边分别为左右子树的中序序列
    int idx;
    for (idx = 0; idx < len; idx++)
    {
        if (in_order[idx] == root->data)
            break;
    }
    // 递归填写左右子树根指针
    root->lchild = restore(idx, p_order + 1, in_order);
    root->rchild = restore(len - idx - 1, p_order + 1 + idx, in_order + idx + 1);
    return root;
};

// 遍历二叉树
template <typename T>
void bintree<T>::traverse(void (*visit)(T &), TRAVERSETYPE type)
{
    switch (type)
    {
    case PREORDER:
    {
        preorder(_root, visit);
        break;
    }
    case INORDER:
    {
        inorder(_root, visit);
        break;
    }
    case POSTORDER:
    {
        postorder(_root, visit);
        break;
    }
    case PREORDERNOCURSION:
    {
        preorder_nocursion(_root, visit);
        break;
    }
    case INORDERNOCURSION:
    {
        inorder_nocursion(_root, visit);
        break;
    }
    case POSTORDERNOCURSION:
    {
        postorder_nocursion(_root, visit);
        break;
    }
    default:
        break;
    }
};

template <typename T>
void bintree<T>::preorder(Node<T> *p, void (*visit)(T &))
{
    if (p)
    {
        visit(p->data);
        preorder(p->lchild, visit);
        preorder(p->rchild, visit);
    }
};

template <typename T>
void bintree<T>::inorder(Node<T> *p, void (*visit)(T &))
{
    if (p)
    {
        inorder(p->lchild, visit);
        visit(p->data);
        inorder(p->rchild, visit);
    }
};

template <typename T>
void bintree<T>::postorder(Node<T> *p, void (*visit)(T &))
{
    if (p)
    {
        postorder(p->lchild, visit);
        postorder(p->rchild, visit);
        visit(p->data);
    }
};

template <typename T>
void bintree<T>::preorder_nocursion(Node<T> *p, void (*visit)(T &))
{
    sqstack<Node<T> *> s;
    s.push(_root);
    while (!s.empty())
    {
        Node<T> *p = s.pop();
        if (p->rchild)
            s.push(p->rchild);
        if (p->lchild)
            s.push(p->lchild);
        visit(p->data);
    }
};

template <typename T>
void bintree<T>::inorder_nocursion(Node<T> *p, void (*visit)(T &))
{

    sqstack<Node<T> *> s;
    Node<T> *ptr = p; //ptr指针表示当前进度
    while (!s.empty() || ptr)
    {
        // 对于每个顶点,以他为根访问的第一个节点必定是其最左叶子结点
        while (ptr)
        {
            s.push(ptr);
            ptr = ptr->lchild;
        }
        ptr = s.pop(); //将ptr指向当前访问节点
        visit(ptr->data);
        ptr = ptr->rchild; //将ptr指向被访问节点的右孩子
    }
};

template <typename T>
void bintree<T>::postorder_nocursion(Node<T> *p, void (*visit)(T &)){

};