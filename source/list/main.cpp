/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-11-19 22:48:01
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "list/input.h"
#include "list/list.h"
template <typename T>
void visit(T &elem)
{
    cout << elem << " ";
}

int main(int argc, char const *argv[])
{
    const int len = 30;
    int A[len] = {0};
    get_input(A, len);
    // 1.构造一个新列表
    list<int> l(A, len);
    cout << "1.新列表为 : ";
    l.traverse(visit);

    // 2.唯一化
    cout << "2.唯一化后的列表为 : ";
    cout << endl;

    l.traverse(visit);
    // 3.选择排序
    cout << "3.选择排序的结果为 : ";
    cout << endl;

    // 4.插入排序
    cout << "3.插入排序的结果为 : ";
    cout << endl;

    // 5.归并排序
    cout << "3.归并排序的结果为 : ";
    cout << endl;
    l.sort(MERGESORT);
    l.traverse(visit);

    return 0;
}
