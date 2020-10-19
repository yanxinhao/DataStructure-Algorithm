/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-20 02:03:18
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include "graph/graphmatrix.h"

// -------------------------------------- 基本操作 --------------------------------------
// 构造
template <typename Tv, typename Te>
GraphMatrix<Tv, Te>::GraphMatrix(int n, const Tv vtx)
{
    _n = 0;
    _e = 0;

    // 顶点初始化
    for (int i = 0; i < n; i++)
        insert(vtx);
}

template <typename Tv, typename Te>
GraphMatrix<Tv, Te>::GraphMatrix(int n_vtx, const Tv *vtx, int n_edge, Te edge[][4])
{

    _n = 0;
    _e = 0;
    // 顶点插入
    for (int i = 0; i < n_vtx; i++)
    {
        insert(vtx[i]);
    }

    // 边插入
    for (int i = 0; i < n_edge; i++)
    {
        insert(edge[i][0], edge[i][1], edge[i][2], edge[i][3]);
    }
};

// 析构
template <typename Tv, typename Te>
GraphMatrix<Tv, Te>::~GraphMatrix()
{
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _n; j++)
            if (exists(i, j))
            {
                delete E[i][j];
                E[i][j] = NULL;
            }
}

// 遍历图
template <typename Tv, typename Te>
void GraphMatrix<Tv, Te>::traverse(void (*visit)(Te &))
{
    // 先打印一行点
    cout << "  ";
    for (int i = 0; i < numVertex(); i++)
    {
        cout << "|" << vertex(i);
    }
    cout << "|" << endl;

    for (int i = 0; i < _n; i++)
    {
        cout << "|" << vertex(i) << "|";
        for (int j = 0; j < _n; j++)
        {
            if (exists(i, j))
                visit(edge(i, j));
            else
                cout << " |";
        }
        cout << endl;
    }
}

// 遍历生成树
template <typename Tv, typename Te>
void GraphMatrix<Tv, Te>::traversetree(void (*visit)(Te &))
{
    // 先打印一行点
    cout << "  ";
    for (int i = 0; i < numVertex(); i++)
    {
        cout << "|" << vertex(i);
    }
    cout << "|" << endl;

    for (int i = 0; i < _n; i++)
    {
        cout << "|" << vertex(i) << "|";
        for (int j = 0; j < _n; j++)
        {
            if (exists(i, j) && (status(i, j) == TREE))
                visit(edge(i, j));
            else
                cout << " |";
        }
        cout << endl;
    }
}
// -------------------------------------- 顶点操作 --------------------------------------
template <typename Tv, typename Te>
int GraphMatrix<Tv, Te>::insert(const Tv &vtx)
{
    //1.边节点每一行增加一个边
    for (int i = 0; i < _n; i++)
        E[i].insert((Edge<Te> *)NULL);
    _n++;

    //2.增加新的一行边
    E.insert(Vector<Edge<Te> *>(_n, _n, (Edge<Te> *)NULL));
    return V.insert(Vertex<Tv>(vtx));
}
template <typename Tv, typename Te>
Tv GraphMatrix<Tv, Te>::remove(int i)
{
    // 1.把第i行,即i边节点的所有出边清空
    for (int j = 0; j < _n; j++)
    {
        if (exists(i, j))
        {
            delete E[i][j];
            V[j].inDegree--;
            _e--;
        }
    }
    // 2.删除第i行
    E.remove(i);
    _n--;
    // 3.删除第i个节点
    Tv vBak = vertex(i);
    V.remove(i);
    // 4.删除i节点的所有入边,即第i列
    for (int j = 0; j < _n; j++)
    {
        if (Edge<Te> *x = E[j].remove(i))
        {
            delete x;
            V[j].outDegree--;
            _e--;
        }
    }
    return vBak;
}

// -------------------------------------- 边操作 --------------------------------------
// 边插入
template <typename Tv, typename Te>
void GraphMatrix<Tv, Te>::insert(const Te &edge, int w, int i, int j)
{
    // if (exists(i, j))
    //     return;
    E[i][j] = new Edge<Te>(edge, w);
    _e++;
    V[i].outDegree++;
    V[j].inDegree++;
}
// 边删除
template <typename Tv, typename Te>
Te GraphMatrix<Tv, Te>::remove(int i, int j)
{
    Te eBak = edge(i, j);
    delete E[i][j];
    E[i][j] = NULL;
    _e--;
    V[i].outDegree--;
    V[j].inDegree--;
    return eBak;
};