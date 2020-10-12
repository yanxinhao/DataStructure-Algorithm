/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-12 22:25:42
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include<iostream>
#define swap(a, b) { int t = a; a = b; b = t; }
bool bubblesort(int A[],int n){
    bool sorted;
    for (sorted=false; sorted=!sorted; n--)
    {
        for (int i = 0; i < n-1; i++)
        {
            if (A[i]>A[i+1])
            {
                swap(A[i],A[i+1]);
                sorted=false;
            }
            
        }
    }
    return sorted;
}