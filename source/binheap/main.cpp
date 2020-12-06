/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-06 21:13:11
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "binheap/compl_heap.h"
#include "binheap/input.h"
using namespace std;
template <typename T>
void visit(T &elem)
{
    cout << elem << " ";
}
int main(int argc, char const *argv[])
{
    cout << "---------------heap---------------" << endl;
    const int len = 30;
    int A[len] = {0};
    get_input(A, len);
    Vector<int> v(A, 0, len);
    // 1.建堆
    cout << "初始的序列为: " << v << endl;
    ComplHeap<int> heap(v);
    cout << "1.建堆的结果为 :";
    heap.traverse(visit);
    cout << endl;
    // 2.堆排序
    ComplHeap<int>::heapsort(v);
    cout << "2.堆排序结果为 :" << v << endl;
    // 3.堆插入
    cout << "3.插入元素 999 :";
    heap.insert(999);
    heap.traverse(visit);
    cout << endl;
    // 4.delmax
    cout << "4.delmax 999 :";
    heap.delmax();
    heap.traverse(visit);
    cout << endl;
    cout << "堆排序输出: ";
    heap.heapsort();
    heap.traverse(visit);
    cout << endl;
    return 0;
}
