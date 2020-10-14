/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-13 22:56:15
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "stack/input.h"
#include"stack/sqstack.h"
using namespace std;

template <typename T>
void visit(T &elem)
{
    cout << elem << " ";
}

template <typename T>
void change(T &elem)
{
    elem = 0;
}
int main()
{
    const int len = 30;
    int A[len] = {0};
    get_input(A, len);
    sqstack<int> s(A,0,len);
    // 1.遍历
    cout<<"1.遍历 traverse(visit): ";
    s.traverse(visit);

    // 2.push
    cout<<"2.push(10000): ";
    s.push(10000);
    s.traverse(visit);

     // 3.pop
    cout<<"3.pop: ";
    s.pop();s.pop();s.pop();
    s.traverse(visit);

    // 3.top
    cout<<"4.top: "<<s.top()<<endl;
    return 0;
}