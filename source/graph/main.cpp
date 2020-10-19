/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-20 02:06:26
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "graph/graph.h"
#include "graph/input.h"
template <typename Te>
void visit(Te &elem)
{
    cout << elem << "|";
}

template <typename Tv>
void visit_vertex(Tv &data)
{
    cout << data << " ";
}

int main(int argc, char const *argv[])
{

    GraphMatrix<char, int> g_bfs(8, vtx_bfs, 22, edge_bfs);
    GraphMatrix<char, int> g_dfs(10, vtx_dfs, 26, edge_dfs);
    GraphMatrix<char, int> g_prim(8, vtx_prim, 30, edge_prim);
    // 1.建图,打印邻接矩阵
    cout << "1.建图,打印邻接矩阵 :" << endl;
    cout << "--------------------------------------------------------" << endl;
    g_bfs.traverse(visit);
    cout << "--------------------------------------------------------" << endl;
    g_dfs.traverse(visit);
    // 2.测试寻找邻居
    cout << "--------------------------------------------------------" << endl;
    cout << "2.寻找邻居 firstNbr(9) firstNbr(0) :";
    cout << g_bfs.firstNbr(9) << " " << g_bfs.firstNbr(0) << endl;

    // 3.遍历
    cout << "3.遍历 : " << endl;
    // 深度优先
    cout << "DFS : ";
    g_dfs.dfs(0, visit_vertex);
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    g_dfs.traversetree(visit);
    cout << "--------------------------------------------------------" << endl;

    cout << "DFSPU : ";
    g_dfs.pfs(0, DFSPU<char, int>());
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    g_dfs.traversetree(visit);
    cout << "--------------------------------------------------------" << endl;
    cout << endl;
    // 广度优先
    cout << "BFS : ";
    g_bfs.bfs(0, visit_vertex);
    cout << "--------------------------------------------------------" << endl;
    g_bfs.traversetree(visit);
    cout << "--------------------------------------------------------" << endl;

    cout << "BFSPU : ";
    g_bfs.pfs(0, BFSPU<char, int>());
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    g_bfs.traversetree(visit);
    cout << "--------------------------------------------------------" << endl;
    // 优先级搜索
    cout << "4.优先级搜索 : " << endl;
    g_prim.pfs(0, PrimPU<char, int>());
    cout << "Prim :" << endl;
    cout << "--------------------------------------------------------" << endl;
    g_prim.traversetree(visit);
    cout << "--------------------------------------------------------" << endl;

    g_prim.pfs(0, DijkstraPU<char, int>());
    cout << "Dijkstra :" << endl;
    cout << "--------------------------------------------------------" << endl;
    g_prim.traversetree(visit);
    cout << "--------------------------------------------------------" << endl;
    return 0;
}
