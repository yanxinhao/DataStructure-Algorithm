/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-14 17:57:50
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include"tree/binnode.h"

#define stature(p) ((p)?(p)->height:-1) //节点高度，约定空树的高度为-1

template <typename T>
class BinTree
{
private:
    int _size;
    BinNodePosi(T) _root;
    void createbintree(BinNodePosi(T) subtree,const T* A,int i,int n);
    virtual int updateHeight(BinNodePosi(T) x);//更新节点x的高度
    void updateHeightAbove(BinNodePosi(T) x);

public:
    int size() const{return _size;};
    bool empty() const{return !_root;};
    BinNodePosi(T) root() const{return _root;}
    BinTree(/* args */);
    BinTree(const T* A,int n);
    ~BinTree();

    BinNodePosi(T) insertAsRc(BinNodePosi(T) x,const T& e);
    BinNodePosi(T) insertAsLc(BinNodePosi(T) x,const T& e);

    // 前序遍历
    // 中序遍历
    // 后序遍历
};

#include"tree/bintree_implement.h"