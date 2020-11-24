/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-11-24 19:28:51
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "stack/sqstack.h"
#include "stack/stack_algorithms.h"
bool paren(string expr)
{
    sqstack<char> s;
    string::iterator iter = expr.begin();
    while (iter != expr.end())
    {
        if (*iter == '(')
            s.push(*iter);
        else if (*iter == ')')
        {
            if (!s.empty())
                s.pop();
            else
                return false;
        }
        iter++;
    }
    return true ? s.empty() : false;
}