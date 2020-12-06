/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-06 17:52:55
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "vector/input.h"
#include "vector/vector.h"
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
    Vector<int> v(A, 0, len);
    cout << v;
    Vector<int *> test(1, 0, NULL);
    for (int i = 0; i < 10; i++)
    {
        test.insert(NULL);
        test.traverse(visit);
    }
    // test.insert(1);
    // 1.遍历
    cout << "1.遍历 traverse(visit): ";
    v.traverse(visit);
    // 2.插入insert(5,100000);
    cout << "2.插入 insert(5,75): ";
    v.insert(5, 75);
    v.traverse(visit);

    // 3.删除
    cout << "3.删除 remove(0,5) : ";
    v.remove(0, 5);
    v.traverse(visit);

    // ------------------若为无序向量-----------------
    // 4.查找

    // 5.唯一化
    // cout<<"5.去重 deduplicate : ";
    // v.deduplicate();
    // v.traverse(visit);

    // cout<<"5.无序向量唯一化 deduplicate_2 : ";
    // v.deduplicate();
    // v.traverse(visit);

    // ------------------若为有序向量-----------------

    // 6.逆序数

    // 7.有序向量排序
    // cout<<"7.排序 bubblesort : ";
    // v.sort(0,v.size());
    // v.traverse(visit);

    cout << "7.排序 mergesort : ";
    v.sort(0, v.size(), MERGESORT);
    v.traverse(visit);
    // 8.有序向量唯一化
    cout << "8.有序向量唯一化 uniquify : ";
    v.uniquify();
    v.traverse(visit);
    // 9.有序向量二分查找
    cout << "9.有序向量二分查找 binsearch : ";
    Rank r = v.search(33, 0, v.size());
    v.traverse(visit);
    cout << "the index of 75 : " << r << endl;

    return 0;
}
