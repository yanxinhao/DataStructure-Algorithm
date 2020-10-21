/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-21 19:24:10
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include <iostream>
using namespace std;
// 普通递归算法
// 分而治之
int matrix_multi_order(const int *p, const int &n);
int divide_and_conquer(const int *p, const int &i, const int &j);

// 动态规划
struct solution
{
    int **sol;
    int optimum;
    int len;
    solution(int **p, int n, int l) : sol(p), optimum(n), len(l) { ; };
    solution(const solution &s)
    {
        optimum = s.optimum;
        len = s.len;
        for (int i = 0; i < s.len + 1; i++)
        {
            sol[i] = new int[s.len + 1];
            for (int j = 0; j < s.len + 1; j++)
                sol[i][j] = s.sol[i][j];
        }
    }
    ~solution()
    {
        for (int i = 0; i < len; i++)
            delete[] sol[i];
        delete[] sol;
    }
};
// 带备忘的自顶向下
solution memoization_mtx_multi_order(const int *p, const int &n);
int memoization_mtx_multi_order_aux(const int *p, const int &i, const int &j, int **m, int **s);
// 自底向上法

solution bottom_up_mtx_multi_order(const int *p, const int &n);
void print_solution(int **sol, const int &i, const int &j);