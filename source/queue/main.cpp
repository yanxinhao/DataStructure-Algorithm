/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-18 22:56:26
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "queue/input.h"
#include "queue/queue.h"
template <typename T>
void visit(T &elem)
{
    cout << elem << " ";
}

int main(int argc, char const *argv[])
{
    const int len = 30;
    int A[len] = {0};
    Queue<int> q;
    get_input(A, len);
    for (int i = 0; i < len; i++)
    {

        q.enqueue(A[i]);
    }
    q.traverse(visit);
    q.dequeue();
    q.traverse(visit);
    cout << "队头 : " << q.front() << endl;
    return 0;
}
