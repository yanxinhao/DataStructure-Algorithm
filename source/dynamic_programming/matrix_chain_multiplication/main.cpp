/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-21 19:17:29
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "matrix_chain_multiplication/mtx_chain_multi.h"
int main(int argc, char const *argv[])
{
    // 输入的矩阵序列
    const int n = 6;                            //矩阵个数
    int p[n + 1] = {30, 35, 15, 5, 10, 20, 25}; //每个矩阵的规模为(i,i+1)
    cout << "分而治之 : "
         << " the minimum multiplication time is " << matrix_multi_order(p, n) << endl;
    //
    solution result = bottom_up_mtx_multi_order(p, n);
    cout << "自底向上 : "
         << " the minimum multiplication time is " << result.optimum << endl;
    print_solution(result.sol, 1, n);
    cout << endl;

    solution slt = memoization_mtx_multi_order(p, n);
    cout << "带备忘的自顶向下 : "
         << " the minimum multiplication time is " << slt.optimum << endl;
    print_solution(slt.sol, 1, n);
    cout << endl;

    return 0;
}
