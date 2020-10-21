/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-21 19:20:39
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "matrix_chain_multiplication/mtx_chain_multi.h"
// 普通递归算法
int matrix_multi_order(const int *p, const int &n)
{
    return divide_and_conquer(p, 1, n);
};
// 分而治之
int divide_and_conquer(const int *p, const int &i, const int &j)
{
    if (i == j)
        return 0;
    int num = INT_MAX;
    for (int k = i; k < j; k++)
    {
        num = min(num, divide_and_conquer(p, i, k) + divide_and_conquer(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return num;
};

// 动态规划
// 带备忘的自顶向下
solution memoization_mtx_multi_order(const int *p, const int &n)
{
    // 新建一个子问题集m[i,j]
    int **m = new int *[n + 1]; //m[i][j]为乘法次数
    int **s = new int *[n + 1]; //s[i][j]为中间分割的位置k
    for (int i = 0; i < n + 1; i++)
    {
        m[i] = new int[n + 1];
        s[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            m[i][j] = INT_MAX;
            s[i][j] = -1;
        }

        m[i][i] = 0;
    }
    int optimum = memoization_mtx_multi_order_aux(p, 1, n, m, s);
    solution result(s, optimum, n);
    // 析构
    for (int i = 0; i < n; i++)
        delete[] m[i];
    delete[] m;

    return result;
};
int memoization_mtx_multi_order_aux(const int *p, const int &i, const int &j, int **m, int **s)
{
    if (i == j)
        return 0;
    if (m[i][j] != INT_MAX)
        return m[i][j];
    for (int k = i; k < j; k++)
    {
        int num = memoization_mtx_multi_order_aux(p, i, k, m, s) + memoization_mtx_multi_order_aux(p, k + 1, j, m, s) + p[i - 1] * p[k] * p[j];
        if (m[i][j] > (num))
        {
            m[i][j] = num;
            s[i][j] = k;
        }
    }
    return m[i][j];
};
// 自底向上法
solution bottom_up_mtx_multi_order(const int *p, const int &n)
{
    // 新建一个子问题集m[i,j]
    int **m = new int *[n + 1]; //m[i][j]为乘法次数
    int **s = new int *[n + 1]; //s[i][j]为中间分割的位置k
    for (int i = 0; i < n + 1; i++)
    {
        m[i] = new int[n + 1];
        s[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            m[i][j] = INT_MAX;
            s[i][j] = -1;
        }

        m[i][i] = 0;
    }
#if 1
    // 分析对子问题的依赖关系得,应该以长度递增的顺序求解子问题
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n + 1 - len; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                if (m[i][j] > m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j])
                {
                    m[i][j] = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    s[i][j] = k;
                }
            }
        }
    }

#else
    // 这种想当然的遍历策略是错误的，有些问题的子问题都还没有被解决(没有弄清楚当前问题到底依赖哪些子问题)
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = i; k < j; k++)
            {
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }
#endif
    // 保存结果,并析构动态内存
    int result = m[1][n];
    for (int i = 0; i < n; i++)
        delete[] m[i];
    delete[] m;
    solution sol(s, result, n);
    return sol;
};

void print_solution(int **sol, const int &i, const int &j)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    int k = sol[i][j];
    cout << "(";
    print_solution(sol, i, k);
    print_solution(sol, k + 1, j);
    cout << ")";
};