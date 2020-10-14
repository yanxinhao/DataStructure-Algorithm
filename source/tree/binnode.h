/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-14 17:28:39
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include <iostream>
#define BinNodePosi(T) BinNode<T>*

template<typename T>
struct BinNode 
{
    BinNodePosi(T) parent,lchild,rchild;
    T data;
    int height;
    BinNode(const T& e,BinNodePosi(T) p=NULL,BinNodePosi(T) l=NULL,BinNodePosi(T) r=NULL,int h=0):data(e),parent(p),lchild(l),rchild(r),height(h)  {};
    int size();//
    BinNodePosi(T) insertAsLc(const T& e);
    BinNodePosi(T) insertAsRc(const T& e);
};

template<typename T>
int BinNode<T>::size(){
    int s=1;//计入本身
    if(lchild) s+=lchild->size();
    if(rchild) s+=rchild->size();
    return s;
}

template<typename T>
BinNodePosi(T) BinNode<T>::insertAsLc(const T& e){
    lchild=new BinNode(e,this);
}

template<typename T>
BinNodePosi(T) BinNode<T>::insertAsRc(const T& e){
    rchild=new BinNode(e,this);
}