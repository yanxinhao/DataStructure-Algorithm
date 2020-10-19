/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-18 22:54:50
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once

#include "vector/vector.h"
template <typename T>
class Queue : public Vector<T>
{
public:
    void enqueue(const T &e) { this->insert(e); };
    T dequeue() { return this->remove(0); };
    T front() { return (*this)[0]; }
};
