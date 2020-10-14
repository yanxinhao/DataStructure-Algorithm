/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-14 10:31:27
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include"vector/vector.h"

template <typename T>
class sqstack : public Vector<T>
{
private:
    /* data */
public:
    sqstack(/* args */);
    sqstack(const T* A,Rank lo,Rank hi);
    ~sqstack();
    bool push(const T& e){this->insert(this->size(),e);};
    T pop(){return this->remove(this->size()-1);};
    T top(){
        if (!this->empty())
            return (*this)[this->size()-1];
        else{
            T data;
            cerr<<"stack is empty"<<endl;
            return data;
        }
    }
};


template <typename T>
sqstack<T>::sqstack(/* args */)
{
}

template <typename T>
sqstack<T>::sqstack(const T* A,Rank lo,Rank hi):Vector<T>(A,lo,hi)
{

};

template <typename T>
sqstack<T>::~sqstack()
{
}

