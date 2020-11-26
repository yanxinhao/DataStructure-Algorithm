/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-11-24 21:04:40
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "stack/input.h"
#include "stack/sqstack.h"
#include "stack/stack_algorithms.h"
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
    sqstack<int> s(A, 0, len);
    // 1.遍历
    cout << "1.遍历 traverse(visit): ";
    s.traverse(visit);

    // 2.push
    cout << "2.push(10000): ";
    s.push(10000);
    s.traverse(visit);

    // 3.pop
    cout << "3.pop: ";
    int len_s = s.size();
    for (int i = 0; i < len_s; i++)
    {
        s.pop();
    }
    // s.pop();s.pop();s.pop();
    s.traverse(visit);

    // 3.top
    cout << "4.top: " << s.top();
    s.traverse(visit);
    cout << endl;

    // 4.parentheses
    cout << "5.parentheses ;";
    string expression = "(a+b)*c)+(d+5*e/2";
    cout << "the result of " << expression << " :" << paren(expression) << endl;

    cout << "6.permute ;";
    expression = "(a+b)*c";
    cout << "the result of " << expression << " : ";
    permute(expression, 0, expression.size());
    return 0;
}