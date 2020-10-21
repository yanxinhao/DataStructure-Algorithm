/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-21 16:09:09
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "cut_rod/cut_rod.h"
int main(int argc, char const *argv[])
{
    const int len = 10;
    int p[len] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int len_rod = 18;
    // 减而治之
    cout << "1.减而治之 :"
         << "the best income of rod of " << len_rod << " length : " << cut_rod(p, len, len_rod) << endl;
    // 动态规划
    cout << "2.动态规划 :" << endl;
    cout << "(1) 带备忘的自顶向下 :"
         << "the best income of rod of "
         << len_rod << " length : " << memoization_cut_rod(p, len, len_rod) << endl;
    cout << "(2) 自底向上 :"
         << "the best income of rod of "
         << len_rod << " length : " << bottom_up_cut_rod(p, len, len_rod) << endl;
    cout << "(3) 重构解(自底向上法) : "
         << "the best solution of rod of "
         << len_rod << " length : ";
    print_cut_rod_solution(bottom_up_cut_rod_solution(p, len, len_rod));

    return 0;
}
