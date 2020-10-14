/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-13 22:57:40
 * @LastEditors: yanxinhao
 * @Description: 
 */

#pragma once
#include"vector/vector.h"

template <typename T>
bool Vector<T>::sort(Rank lo,Rank hi,SORTING kind){
    bool sorted=false;
    switch (kind)
    {
    case BUBBLESORT:
        sorted=bubblesort(lo,hi);
        break;
    case MERGESORT:
        sorted=mergesort(lo,hi);
        break;
    default:
        break;
    }
    return sorted;
}

// 冒泡排序
// [lo,hi)
template <typename T>
Rank Vector<T>::bubble(Rank lo,Rank hi){
    Rank last=lo;
    // 两种写法
    #if 0
        for (int i = lo; i < hi-1; i++)
        {
            if (_elem[i]>_elem[i+1])
            {
                swap(_elem[i],_elem[i+1]);
                last=i+1;//更新最右侧逆序对位置记录
            }
            
        }
    #else
        while (++lo<hi)
        {
            if(_elem[lo-1]>_elem[lo]){
                swap(_elem[lo-1],_elem[lo]);
                last=lo;
            }
        }
            
    #endif
    return last;
};

// [lo,hi)
template <typename T>
bool Vector<T>::bubblesort(Rank lo,Rank hi){
    while (lo<(hi=bubble(lo,hi)));    
    return true;
};


// 归并排序
template <typename T>
bool Vector<T>::mergesort(Rank lo,Rank hi){
    if((hi-lo)<2) return true;//单个自然数排序，当然有序
    Rank mid=(lo+hi)>>1;
    mergesort(lo,mid);
    mergesort(mid,hi);
    merge(lo,mid,hi);
    return true;
};

template <typename T>
bool Vector<T>::merge(Rank lo,Rank mid,Rank hi){
    int lb=mid-lo,lc=hi-mid;
    T* const B=new T[lb];
    T* const C=_elem+mid;
    T* const A = _elem+lo;
    for (int i = 0; i < lb; i++) B[i]=_elem[lo+i];//复制前向量
    Rank i=0,j=0,k=0;
    #if 1
    while (j<lb)
    {
        if((k<lc)&&(C[k]<B[j])) A[i++]=C[k++];//C存在并且C比B小时
        else
            A[i++]=B[j++];//C不存在或者C不必B小时
    }
    
    #else
    while ((j<lb)||(k<lc))
    {
        if((j<lb)&&(lc<=k||B[j]<C[k]))
            A[i++]=B[j++];
        else
            A[i++]=C[k++];
    }
    #endif
    delete [] B;
    return true;
};
