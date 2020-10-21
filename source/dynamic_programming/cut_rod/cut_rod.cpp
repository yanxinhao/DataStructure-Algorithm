/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-21 16:09:00
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "cut_rod/cut_rod.h"
//普通的递归算法
// 减而治之
int cut_rod(const int *p, const int &list_len, const int &n)
{
    if (n == 0)
        return 0;
    int q = INT_MIN;
    // 问题规模降低时的最大收益
    for (int i = 1; i <= min(list_len, n); i++)
    {
        if (q < p[i - 1] + cut_rod(p, list_len, n - i))
            q = p[i - 1] + cut_rod(p, list_len, n - i);
    }
    return q;
}

// 动态规划
// 带备忘的自顶向下
int memoization_cut_rod(const int *p, const int &list_len, const int &n)
{

    // 建立备忘录并初始化
    // r[0]=0,其他地方都为INT_MIN
    int *r = new int[n + 1]{0};
    for (int i = 1; i <= n; i++)
    {
        r[i] = INT_MIN;
    }
    int result = memoization_cut_rod_aux(p, list_len, r, n);
    delete[] r;
    return result;
}

int memoization_cut_rod_aux(const int *p, const int &list_len, int *r, const int &n)
{
    // 首先查询备忘录,若存在则代表是相同的子问题，直接返回
    // 注意这里递归问题的最小问题n=0也在备忘录中（直接查询既可，无需单独对最小问题进行处理）
    if (r[n] >= 0)
        return r[n];
    int q;
    q = INT_MIN;
    for (int i = 1; i <= min(list_len, n); i++)
        q = max(q, p[i - 1] + memoization_cut_rod_aux(p, list_len, r, n - i));
    r[n] = q;
    return q;
};

// 自底向上版本
int bottom_up_cut_rod(const int *p, const int &list_len, const int &n)
{
    // 初始化备忘录
    int *r = new int[n + 1]{0};
    for (int i = 1; i <= n; i++)
    {
        r[i] = INT_MIN;
    }

    // 一步步将问题规模慢慢增大,并记录已经完成的问题到备忘录中
    int q;
    for (int i = 1; i <= n; i++)
    {
        q = INT_MIN;
        for (int j = 1; j <= min(i, list_len); j++)
        {
            q = max(q, p[j - 1] + r[i - j]);
        }
        r[i] = q;
    }
    int result = r[n];
    delete[] r;
    return result;
};

// 自底向上重构解
solution bottom_up_cut_rod_solution(const int *p, const int &list_len, const int &n)
{
    // 初始化备忘录
    int *r = new int[n + 1]{0};
    int *s = new int[n + 1]{0};
    for (int i = 1; i <= n; i++)
    {
        r[i] = INT_MIN;
        s[i] = INT_MIN;
    }

    // 一步步将问题规模慢慢增大,并记录已经完成的问题到备忘录中
    int q;
    for (int i = 1; i <= n; i++)
    {
        q = INT_MIN;
        int j;
        for (j = 1; j <= min(i, list_len); j++)
        {
            if (q < p[j - 1] + r[i - j])
            {
                q = p[j - 1] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = q;
    }
    int result = r[n];
    delete[] r;
    solution sol(result, s, n);
    return sol;
};

// 根据重构的解打印解
void print_cut_rod_solution(const solution &sol)
{
    int *s = sol.sol;
    int len = sol.len;
    while (s[len])
    {
        cout << s[len] << " ";
        len -= s[len];
    }
    cout << endl;
};