/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-06 21:11:55
 * @LastEditors: yanxinhao
 * @Description: 完全二叉堆
 */
#pragma once
#include <iostream>
#include <vector/vector.h>
typedef int Rank;

/**
 * @brief 完全二叉堆的定义，大根堆
 * 
 * @tparam T 
 */
template <typename T>
class ComplHeap
{
private:
    int _size;
    Vector<T> data;

public:
    ComplHeap(Vector<T> v);
    ~ComplHeap();
    // 因为数组index从0开始
    /**
     * @brief return -1时表示不存在父节点(即当前节点为root)
     * 
     * @param r 
     * @return Rank 
     */
    static Rank parent(Rank r) { return (r + 1) / 2 - 1; }
    static Rank lchild(Rank r, int size) { return (2 * r + 1) < size ? (2 * r + 1) : -1; }
    static Rank rchild(Rank r, int size) { return (2 * r + 2) < size ? (2 * r + 2) : -1; }
    static Rank properparent_max(Rank i, Vector<T> &v, int n); // 根据是大根堆性质来从i及其孩子中选择合适的作为parent
    static Vector<T> heapify(Vector<T> &v);                    //floyd建堆方法
    void percolate_up(Rank i);                                 //上滤算法
    static void percolate_down(Rank i, Vector<T> &v, int n);   //下滤算法
    static void heapsort(Vector<T> &v);                        //堆排序算法
    void heapsort() { heapsort(data); }
    void traverse(void (*visit)(T &)); //遍历算法
    T &delmax();                       //获取堆(优先队列的最大值)
    void insert(const T &elem);        //插入元素到堆
};

#include "binheap/compl_heap_implement.h"