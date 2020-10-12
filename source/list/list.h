/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-13 00:35:12
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include<iostream>
#define Posi<T> ListNode<T>*
template<typename T>
struct ListNode
{
    T data;
    Posi<T> pred;
    Posi<T> succ;
    Posi<T> insertAsPred(const T& e);
    Posi<T> insertAsSucc(const T& e);
};


class list
{
private:
    /* data */
public:
    list(/* args */);
    ~list();
};

list::list(/* args */)
{
}

list::~list()
{
}
