/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-15 15:24:10
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
    CROSS,
    FORWARD,
    BACKWARD
} EStatus;

#define EdgePosi(Te) Edge<Te> *
#define VertexPosi(Tv) Vertex<Tv> *

template <typename Tv, typename Te>
class Graph
{
private:
    void reset(){
        //所有顶点,边的辅助信息复位

    };

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
    virtual int &parent(int i) = 0;     //遍历树中找父亲
    // virtual VertexPosi(Tv) nextNbr(VertexPosi(Tv) vtx);//查找顶点vtx的下一个邻居节点

    //边操作

    //
};

#include "graph/graphmatrix_implement.h"