/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-03 23:30:02
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
    linklist<int> llist(A, len);
    cout << "1.新双向链表为 : ";
    l.traverse(visit);
    cout << "1.新单向链表为 : ";
    llist.traverse(visit);

    // 2.唯一化
    cout << "2.唯一化后的列表为 : ";
    cout << endl;

    // 3.逆置
    cout << "2.双向链表逆置后 : ";
    l.reverse();
    l.traverse(visit);
    cout << "2.单向链表逆置后 : ";
    llist.reverse();
    llist.traverse(visit);
    cout << endl;
    // 4.选择排序
    cout << "4.选择排序的结果为 : ";
    cout << endl;

    // 5.插入排序
    cout << "5.插入排序的结果为 : ";
    cout << endl;

    // 6.归并排序
    cout << "6.归并排序的结果为 : ";
    l.sort(MERGESORT);
    l.traverse(visit);
    cout << endl;

    cout << "------------------------------------------------------------------------408真题:链表算法设计------------------------------------------------------------------------" << endl;
    cout << "2009年42题: 倒数第5个元素为 " << llist.ksearch_2009(5) << endl;
    cout << "2019年41题:";
    llist.switch_2019();
    llist.traverse(visit);
    cout << "2010年42题:";
    llist.circle_move_2010(2);
    llist.traverse(visit);

    return 0;
}
