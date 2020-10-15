/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-15 22:15:39
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
    int parent;
    Vertex(const Tv &d = (Tv)0) : data(d), inDegree(0), outDegree(0), parent(0), status(UNDISCOVERED){};
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
public:
    GraphMatrix() : _n(0), _e(0){};
    GraphMatrix(int n, const Tv vtx);
    ~GraphMatrix();

    virtual int numVertex() { return _n; };
    virtual int numEdge() { return _e; };

    void traverse(void (*visit)(Edge<Te> *));

    // 顶点操作
    virtual Tv &vertex(int i) { return V[i].data; };        //数据
    virtual int inDegree(int i) { return V[i].inDegree; }   //入度
    virtual int outDegree(int i) { return V[i].outDegree; } //出度
    virtual VStatus &status(int i) { return V[i].status; }; //状态
    virtual int &parent(int i) { return V[i].parent; };     //遍历树中找父亲
    int nextNbr(int i, int j)
    {
        while ((-1 < j) && !(exists(i, --j)))
            ;
        return j;
    } //对于顶点i,寻找不包括j的下一个邻接顶点
    int firstNbr(int i) { return nextNbr(i, _n); };
    ;
    int insert(const Tv &vtx); //边删除
    Tv remove(int i);          //顶点删除

    // 边操作
    bool exists(int i, int j) { return (0 <= i) && (i < _n) && (0 <= j) && (j < _n) && E[i][j] != NULL; };
    Te &edge(int i, int j) { return E[i][j]->data; };
    EStatus &status(int i, int j) { return E[i][j]->status; };
    int &weight(int i, int j) { return E[i][j]->weight; };
    void insert(const Te &edge, int w, int i, int j); //边插入
    Te remove(int i, int j);                          //边删除
};

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

// 遍历
template <typename Tv, typename Te>
void GraphMatrix<Tv, Te>::traverse(void (*visit)(Edge<Te> *))
{
    for (int i = 0; i < _n; i++)
    {
        cout << "|";
        for (int j = 0; j < _n; j++)
        {
            visit(E[i][j]);
        }
        cout << "|" << endl;
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