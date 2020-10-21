/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-21 12:31:04
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include <iostream>
using namespace std;
//普通的递归算法
// 减而治之
int cut_rod(const int *p, const int &list_len, const int &n);

// 动态规划
// 带备忘的自顶向下
int memoization_cut_rod(const int *p, const int &list_len, const int &n);
int memoization_cut_rod_aux(const int *p, const int &list_len, int *r, const int &n);
// 自底向上法
int bottom_up_cut_rod(const int *p, const int &list_len, const int &n);
// 最优解的结构
struct solution
{
    int optimum;
    int *sol;
    int len;
    solution(int opt, int *s, int n) : optimum(opt), sol(s), len(n) { ; };
};
// 重构解
solution bottom_up_cut_rod_solution(const int *p, const int &list_len, const int &n);
// 根据重构的结果,真正构造此问题的最优切割方案
void print_cut_rod_solution(const solution &sol);