/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-04 15:39:27
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include <iostream>
typedef enum
{
    UNDISCOVERED,
    DISCOVERED,
    VISITED
} VStatus;
typedef enum
{
    UNDETERMINED,
    TREE,
    CROSS, //BFS tree
    FORWARD,
    BACKWARD
} EStatus;

#define EdgePosi(Te) Edge<Te> *
#define VertexPosi(Tv) Vertex<Tv> *

/**
 * @brief 图的基类，声明一些基本操作，具体的图实现有邻接矩阵或者邻接表
 * 
 * @tparam Tv 
 * @tparam Te 
 */
template <typename Tv, typename Te>
class Graph
{
private:
    virtual void reset() = 0; //所有顶点,边的辅助信息复位

public:
    Graph(/* args */){};
    ~Graph(){};
    virtual int numVertex() = 0;
    virtual int numEdge() = 0;

    // 顶点操作
    virtual Tv &vertex(int i) = 0;      //数据
    virtual int inDegree(int i) = 0;    //入度
    virtual int outDegree(int i) = 0;   //出度
    virtual VStatus &status(int i) = 0; //状态
    virtual int &dTime(int i) = 0;
    virtual int &fTime(int i) = 0;
    virtual int &parent(int i) = 0; //遍历树中找父亲
    virtual int &priority(int) = 0;
    virtual int nextNbr(int, int) = 0;
    virtual int firstNbr(int) = 0;

    //边操作
    virtual EStatus &status(int i, int j) = 0;
    virtual int &weight(int i, int j) = 0;
    //搜索
    void BFS(int v, int &clock, void (*visit)(Tv &));
    void DFS(int v, int &clock, void (*visit)(Tv &));
    void bfs(int s, void (*visit)(Tv &));
    void dfs(int s, void (*visit)(Tv &));
    // 优先级搜索
    template <typename PU>
    void pfs(int s, PU prioUpdater);
};
#include "graph/graph_implement.h"
#include "graph/graphmatrix.h"