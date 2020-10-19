/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-20 02:07:26
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include "graph/graph.h"
#include "queue/queue.h"

// 搜索(BFS,DFS)
template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int &clock, void (*visit)(Tv &))
{
    Queue<int> Q;
    Q.enqueue(v);
    status(v) = DISCOVERED;
    while (!Q.empty())
    {
        int current_v = Q.dequeue();
        dTime(current_v) = ++clock;
        for (int i = firstNbr(current_v); - 1 < i; i = nextNbr(current_v, i))
        {
            if (status(i) == UNDISCOVERED)
            {
                Q.enqueue(i);
                status(i) = DISCOVERED;
                status(current_v, i) = TREE;
                parent(i) = current_v;
            }
            else
            {
                status(current_v, i) = CROSS;
            }
        }
        visit(vertex(current_v));
        status(current_v) = VISITED;
    }
    cout << endl;
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int &clock, void (*visit)(Tv &))
{
    dTime(v) = ++clock;
    status(v) = DISCOVERED;
    visit(vertex(v)); //在这访问的话相当于先序遍历
    for (int i = firstNbr(v); - 1 < i; i = nextNbr(v, i))
    {
        if (status(i) == UNDISCOVERED)
        {
            DFS(i, clock, visit);
            parent(i) = v;
            status(v, i) = TREE;
        }
        else if (status(i) == DISCOVERED)
        {
            status(v, i) = BACKWARD;
            /* code */
        }
        else if (status(i) == VISITED)
        {
            status(v, i) = dTime(v) < dTime(i) ? FORWARD : CROSS;
        }
        status(v) = VISITED;
        fTime(v) = ++clock;
    }
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s, void (*visit)(Tv &))
{
    reset();
    int clock = 0;
    int v = s;
    do
    {
        if (status(v) == UNDISCOVERED)
            BFS(v, clock, visit);
    } while (s != (v = ++v % numVertex()));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s, void (*visit)(Tv &))
{
    reset();
    int clock = 0;
    int v = s;
    do
    {
        if (status(v) == UNDISCOVERED)
            DFS(v, clock, visit);
    } while (s != (v = ++v % numVertex()));
}

// 优先级搜索
template <typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::pfs(int s, PU prioUpdater)
{
    reset();
    priority(s) = 0;
    parent(s) = -1;
    status(s) = VISITED; //将s加入PFS树中
    // 将n-1个顶点和边加入PFS树中
    while (1)
    {
        // 更新s所有邻居的优先级,并更新其父节点
        for (int i = firstNbr(s); - 1 < i; i = nextNbr(s, i))
        {
            prioUpdater(this, s, i);
        }

        // 在所有未加入PFS树的节点中找出优先级最高的点,选为下一个
        for (int shortest = INT_MAX, w = 0; w < numVertex(); w++)
        {
            if (status(w) == UNDISCOVERED)
                if (priority(w) < shortest)
                {
                    shortest = priority(w);
                    s = w;
                }
        }
        if (status(s) == VISITED)
            break;
        status(s) = VISITED; //将新的s加入PFS树
        status(parent(s), s) = TREE;
    }

    // 标记生成树的边
    for (int i = 0; i < numVertex(); i++)
        if (!(parent(i) < 0))
            status(parent(i), i) = TREE;

    return;
}

// 套用优先级搜索
// BFS
template <typename Tv, typename Te>
struct BFSPU
{
    virtual void operator()(Graph<Tv, Te> *g, int s, int w)
    {
        if (g->status(w) == UNDISCOVERED)
            if (g->priority(w) > g->priority(s) + 1)
            {
                g->priority(w) = g->priority(s) + 1;
                g->parent(w) = s;
            }
    }
};

// DFS
template <typename Tv, typename Te>
struct DFSPU
{
    virtual void operator()(Graph<Tv, Te> *g, int s, int w)
    {
        if (g->status(w) == UNDISCOVERED)
            if (g->priority(w) > g->priority(s) - 1)
            {
                g->priority(w) = g->priority(s) - 1;
                g->parent(w) = s;
            }
    }
};
// Prim 八抓鱼找最近的食物
template <typename Tv, typename Te>
struct PrimPU
{
    virtual void operator()(Graph<Tv, Te> *g, int s, int w)
    {
        if (g->status(w) == UNDISCOVERED)
            if (g->priority(w) > g->weight(s, w))
            {
                g->priority(w) = g->weight(s, w);
                g->parent(w) = s;
            }
    }
};

// Dijkstra
template <typename Tv, typename Te>
struct DijkstraPU
{
    virtual void operator()(Graph<Tv, Te> *g, int s, int w)
    {
        if (g->status(w) == UNDISCOVERED)
            if (g->priority(w) > (g->priority(s) + g->weight(s, w)))
            {
                g->priority(w) = g->priority(s) + g->weight(s, w);
                g->parent(w) = s;
            }
    }
};
