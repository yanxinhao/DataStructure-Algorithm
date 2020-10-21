/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-20 01:45:16
 * @LastEditors: yanxinhao
 * @Description: 
 */
char vtx_bfs[9] = "abcdefgs";
int edge_bfs[22][4] = {
    {0, 0, 0, 7},
    {0, 0, 7, 0},
    {0, 0, 0, 4},
    {0, 0, 4, 0},
    {0, 0, 0, 2},
    {0, 0, 2, 0},
    {0, 0, 7, 3},
    {0, 0, 3, 7},
    {0, 0, 7, 2},
    {0, 0, 2, 7},
    {0, 0, 1, 2},
    {0, 0, 2, 1},
    {0, 0, 1, 3},
    {0, 0, 3, 1},
    {0, 0, 1, 6},
    {0, 0, 6, 1},
    {0, 0, 6, 4},
    {0, 0, 4, 6},
    {0, 0, 6, 5},
    {0, 0, 5, 6},
    {0, 0, 4, 5},
    {0, 0, 5, 4}};

char vtx_dfs[11] = "abcdefghij";
int edge_dfs[26][4] = {
    {0, 0, 0, 1},
    {0, 0, 0, 4},
    {0, 0, 0, 3},
    {0, 0, 1, 4},
    {0, 0, 1, 2},
    {0, 0, 2, 5},
    {0, 0, 5, 7},
    {0, 0, 5, 6},
    {0, 0, 7, 6},
    {0, 0, 6, 9},
    {0, 0, 6, 8},
    {0, 0, 6, 3},
    {0, 0, 8, 3},
    {0, 0, 1, 0},
    {0, 0, 4, 0},
    {0, 0, 3, 0},
    {0, 0, 4, 1},
    {0, 0, 2, 1},
    {0, 0, 5, 2},
    {0, 0, 7, 5},
    {0, 0, 6, 5},
    {0, 0, 6, 7},
    {0, 0, 9, 6},
    {0, 0, 8, 6},
    {0, 0, 3, 6},
    {0, 0, 3, 8}};

char vtx_prim[9] = {"ABCDEFGH"};
int edge_prim[30][4] = {
    {0, 4, 0, 1},
    {0, 6, 0, 3},
    {0, 7, 0, 6},
    {0, 12, 1, 2},
    {0, 9, 2, 3},
    {0, 1, 2, 4},
    {0, 2, 2, 5},
    {0, 10, 2, 7},
    {0, 2, 3, 6},
    {0, 13, 3, 4},
    {0, 11, 4, 6},
    {0, 8, 4, 7},
    {0, 5, 4, 5},
    {0, 7, 5, 7},
    {0, 14, 6, 7},
    {0, 4, 1, 0},
    {0, 6, 3, 0},
    {0, 7, 6, 0},
    {0, 12, 2, 1},
    {0, 9, 3, 2},
    {0, 1, 4, 2},
    {0, 2, 5, 2},
    {0, 10, 7, 2},
    {0, 2, 6, 3},
    {0, 13, 4, 3},
    {0, 11, 6, 4},
    {0, 8, 7, 4},
    {0, 5, 5, 4},
    {0, 7, 7, 5},
    {0, 14, 7, 6},
};