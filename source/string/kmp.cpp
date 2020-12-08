/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-08 23:38:12
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "string/string.h"

int MyString::kmp(const char *s, int len) const
{
    int *next = kmp_build_next(s, len);
    int i = 0, n = size();   //主串指针和长度
    int j = 0;               //模式串指针
    while (j < len && i < n) //主串和模式串都还有元素要进行比较
    {
        if (_elem[i] == s[j] || j < 0)
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    delete next;
    return i - j;
};

/**
 * @brief 构建next表，主要思想是要前后k位能匹配，那么最后一位的前k-1位要与最前的k-1匹配，然后在最后一位又与第k位匹配时。next等于(k-1)+1
 * 
 * @param s 
 * @param len 
 * @return int* 
 */
int *MyString::kmp_build_next(const char *s, int len) const
{
    int *N = new int[len];
    int j = 0;
    N[0] = -1;
    int t = -1;
    while (j < len - 1)
    {
        if (s[j] == s[t] || t < 0)
        {
            N[++j] = ++t;
        }
        else
        {
            t = N[t];
        }
    }
    return N;
};