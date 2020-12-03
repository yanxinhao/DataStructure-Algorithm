/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-03 23:45:51
 * @LastEditors: yanxinhao
 * @Description: 单向链表
 */
#pragma once

#include "list/list.h"
template <typename T>
linklist<T>::linklist(/* args */)
{
}

template <typename T>
linklist<T>::linklist(const T *array, int len)
{
    init();
    LNode<T> *p = _header;
    for (int i = 0; i < len; i++)
    {
        LNode<T> *t = new LNode<T>(array[i]);
        p->next = t;
        p = p->next;
        _size++;
    }
};

template <typename T>
linklist<T>::~linklist()
{
}

// 遍历
template <typename T>
void linklist<T>::traverse(void (*visit)(T &))
{
    LNode<T> *p = _header->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    cout << endl;
};

// 逆置
template <typename T>
/**
 * @description: 返回逆置后链表的第一个元素节点
 * @param {p 链表第一个元素节点的指针，注意链表的最后一个节点的next必须为NULL}
 * @return {p 逆置后链表的第一个元素节点}
 */
LNode<T> *linklist<T>::_reverse(LNode<T> *p)
{
    LNode<T> *q = p->next;
    p->next = NULL;
    while (q)
    {
        LNode<T> *r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
};
template <typename T>
void linklist<T>::reverse()
{
    _header->next = _reverse(_header->next);
}

template <typename T>
void linklist<T>::switch_2019()
{
    //step1 根据链表size的大小来将链表分成前后两段
    int len_l = (_size + 1) / 2;
    LNode<T> *L = _header->next;
    int len_r = _size - len_l;
    LNode<T> *R = L;
    for (int i = 0; i < len_l; i++) //找到右边表的第一个元素指针
        R = R->next;

    //step2 逆置右边的链表
    R = _reverse(R);

    //step3 遍历R表并将其节点一个个插入L中,因为L的表长度不小于R
    for (int i = 0; i < len_r; i++)
    {
        LNode<T> *p1 = L->next; //先暂存L的下一个节点
        LNode<T> *p2 = R->next; //先暂存R的下一个节点
        L->next = R;
        R->next = p1;
        L = p1;
        R = p2;
    }
    // 将L的最后一个节点的next置NULL
    L->next = NULL;
};

template <typename T>
T linklist<T>::ksearch_2009(int k)
{
    if (k > _size)
    {
        cerr << "k is bigger than size";
    }
    LNode<T> *p = _header->next;
    LNode<T> *q = _header->next;
    for (int i = 1; i < k; i++)
        q = q->next;
    while (q->next)
    {
        p = p->next;
        q = q->next;
    }
    return p->data;
};

template <typename T>
void linklist<T>::circle_move_2010(int p)
{
    // step1 逆置整个链表
    _header->next = _reverse(_header->next);
    LNode<T> *L = _header->next;
    LNode<T> *R = _header->next;
    //step2 将链表分成两段[1,size-p] [size-p+1,size]
    LNode<T> *t = _header;
    for (int i = 0; i < _size - p; i++)
    {
        R = R->next; //R为右边链表第一个一个元素
        t = t->next; //t为左边链表最后一个元素
    }
    t->next = NULL;

    //step3 分别逆置L和R
    _header->next = _reverse(L);
    LNode<T> *pr = _reverse(R);
    // step4 将L和R重新链接既可
    L->next = pr; //注意这里的L逆置后成了左边的尾
};