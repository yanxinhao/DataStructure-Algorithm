/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-08 23:38:31
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "string/input.h"
#include "string/string.h"
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    MyString t(T, 0, 14);
    cout << t << endl;
    // kmp
    cout << "T is :" << T << endl;
    cout << "S is :" << S << endl;
    cout << "1.kmp的结果为:" << t.kmp(S, 6) << " and next is :" << Vector<int>(t.kmp_build_next(S, 6), 0, 6) << endl;
    ;
    return 0;
}
