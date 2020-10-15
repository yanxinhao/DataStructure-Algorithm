/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-15 21:21:04
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "graph/graph.h"

template <typename Te>
void visit(Edge<Te> *elem)
{
    if (elem)
        cout << elem->data << "    ";
    else
        cout << "     ";
}

int len = 10;
int edge[10][4] = {
    {2, 8, 1, 0},
    {1, 8, 2, 6},
    {6, 8, 3, 9},
    {7, 8, 4, 3},
    {0, 8, 5, 7},
    {9, 8, 6, 1},
    {4, 8, 7, 6},
    {4, 8, 8, 3},
    {8, 8, 9, 0},
    {3, 8, 0, 2},
};
int main(int argc, char const *argv[])
{
    GraphMatrix<char, int> g(len, '#');
    for (int i = 0; i < len; i++)
    {
        g.insert(edge[i][0], edge[i][1], edge[i][2], edge[i][3]);
    }
    // 1.建图,打印邻接矩阵
    cout << "1.建图,打印邻接矩阵 :" << endl;
    cout << "--------------------------------------------------------" << endl;
    g.traverse(visit);
    // 2.测试寻找邻居
    cout << "--------------------------------------------------------" << endl;
    cout << "2.寻找邻居 firstNbr(9) firstNbr(0) :";
    cout << g.firstNbr(9) << " " << g.firstNbr(0) << endl;

    // 3.遍历
    // 深度优先
    // 广度优先
    return 0;
}
