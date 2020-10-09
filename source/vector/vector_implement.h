/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-09 23:47:18
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include<iostream>
using namespace std;
template <typename T>
Vector<T>::Vector(int c)
{
    _elem=new T[_capacity=c];
    _size=0;
};

template <typename T>
void Vector<T>::copyfrom(T const * A,Rank lo,Rank hi)
{
    _elem=new T[_capacity=2*(hi-lo)];
    _size=0;
    while (lo<hi)
    {
        _elem[_size++]=A[lo++];
    }
    
}

template <typename T>
Vector<T>::Vector(T const * A,Rank lo,Rank hi){
    copyfrom(A,lo,hi);
};

template <typename T>
Vector<T>::~Vector()
{
    delete [] _elem;
}



// 遍历
template <typename T>
void Vector<T>::traverse(void (*visit)(T&)) const {
    for (int i = 0; i < _size; i++)
    {
        visit(_elem[i]);
    }
    cout<<endl;
};

// 扩充
template <typename T>
void Vector<T>::expand() {
    if (_size<_capacity)
        return;
    _capacity=max(_capacity,DEFAULT_CAPACITY);
    T* _old_elem=_elem;
    _elem=new T[_capacity<<=1];
    for (int i = 0; i < _size; i++)
    {
        _elem[i]=_old_elem[i];
    }
    delete [] _old_elem;
    
};


// 插入
template <typename T>
void Vector<T>::insert(Rank r,const T& elem){
    if (r>_size)
    {   
        cerr<<"insert error :r must be less than _size"<<endl;
        return;
    }
    
    expand();
    for (int i = _size; i > r; i--)
    {
        _elem[i]=_elem[i-1];
    }
    _elem[r]=elem;
    _size++;
};

// 删除
template <typename T>
// remove [lo,hi)
int Vector<T>::remove(Rank lo,Rank hi){
    if (lo==hi) return 0;
    while (hi<_size)
    {
        _elem[lo++]=_elem[hi++];
    }
    _size=lo;
    // shrink,若有必要，缩小规模
    return hi-lo;
};