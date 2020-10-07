/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-07 17:24:02
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include<iostream>
void get_input(int A[],int n,int low=0,int top=100){
    for(int i =0;i<n;i++){
        A[i]=rand()%(top - low + 1) + low;;
    }
}