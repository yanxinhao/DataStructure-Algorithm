/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-09 23:43:46
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "vector/vector.h"
#include"vector/input.h"
using namespace std;

template<typename T>
void visit(T& elem){
    cout<<elem<<" ";
}

template<typename T>
void change(T& elem){
    elem=0;
}
int main()
{
    int A[20]={0};
    get_input(A,20);
    Vector<int> v(A,0,20);
    // 1.遍历
    cout<<"1.遍历 traverse(visit): ";
    v.traverse(visit);
    // 2.插入insert(5,100000);
    cout<<"2.插入 insert(5,100000): ";
    v.insert(5,100000);
    v.traverse(visit);

    // 3.删除
    cout<<"3.删除 remove(0,5) : ";
    v.remove(0,5);
    v.traverse(visit);
    
    // 4.查找

    // 5.唯一化

    // ------------------若为有序向量-----------------
    // 6.逆序数

    // 7.有序向量唯一化

    // 8.有序向量二分查找

    // 9.有序向量排序
    return 0;
}
