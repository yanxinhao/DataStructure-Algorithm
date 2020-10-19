/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-20 00:53:04
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once

#include "graph/graph.h"
#include "vector/vector.h"

template <typename Tv>
struct Vertex
{
    Tv data;
    int inDegree, outDegree;
    VStatus status;
    int dTime, fTime;
    int parent;
    int priority;
    Vertex(const Tv &d = (Tv)0) : data(d), inDegree(0), outDegree(0), dTime(-1), fTime(-1), priority(INT_MAX), parent(-1), status(UNDISCOVERED){};
};

template <typename Te>
struct Edge
{
    Te data;
    int weight;
    EStatus status;
    Edge(const Te &d = (Te)0, int w = 0) : data(d), weight(w), status(UNDETERMINED){};
};

template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te>
{
private:
    int _n, _e;
    Vector<Vertex<Tv>> V;         //顶点集
    Vector<Vector<Edge<Te> *>> E; //边集
    virtual void reset()
    {
        for (int i = 0; i < _n; i++)
        {
            status(i) = UNDISCOVERED;
            dTime(i) = fTime(i) = -1;
            parent(i) = -1;
            priority(i) = INT_MAX;
            for (int j = 0; j < _n; j++)
            {
                if (exists(i, j))
                {
                    status(i, j) = UNDETERMINED;
                }
            }
        }
    }

public:
    GraphMatrix() : _n(0), _e(0){};
    GraphMatrix(int n, const Tv vtx);
    GraphMatrix(int n_vtx, const Tv *vtx, int n_edge, Te edge[][4]);
    ~GraphMatrix();

    virtual int numVertex() { return _n; };
    virtual int numEdge() { return _e; };

    void traverse(void (*visit)(Te &));
    void traversetree(void (*visit)(Te &));
    // 顶点操作
    virtual Tv &vertex(int i) { return V[i].data; };        //数据
    virtual int inDegree(int i) { return V[i].inDegree; }   //入度
    virtual int outDegree(int i) { return V[i].outDegree; } //出度
    virtual VStatus &status(int i) { return V[i].status; }; //状态
    virtual int &parent(int i) { return V[i].parent; };     //遍历树中找父亲
    virtual int &priority(int i) { return V[i].priority; };
    virtual int &dTime(int i) { return V[i].dTime; };
    virtual int &fTime(int i) { return V[i].fTime; };
    virtual int nextNbr(int i, int j)
    {
        while ((-1 < j) && !(exists(i, --j)))
            ;
        return j;
    } //对于顶点i,寻找不包括j的下一个邻接顶点
    virtual int firstNbr(int i) { return nextNbr(i, _n); };
    ;
    int insert(const Tv &vtx); //顶点插入
    Tv remove(int i);          //顶点删除

    // 边操作
    bool exists(int i, int j) { return (0 <= i) && (i < _n) && (0 <= j) && (j < _n) && E[i][j] != NULL; };
    Te &edge(int i, int j) { return E[i][j]->data; };
    virtual EStatus &status(int i, int j) { return E[i][j]->status; };
    virtual int &weight(int i, int j) { return E[i][j]->weight; };
    void insert(const Te &edge, int w, int i, int j); //边插入
    Te remove(int i, int j);                          //边删除
};

#include "graph/graphmatrix_implement.h"