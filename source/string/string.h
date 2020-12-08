/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-08 23:28:40
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once
#include "vector/vector.h"
/**
 * @brief 基于vector实现的简单string类。用来理解kmp和lcs等字符串相关算法
 * 
 */
class MyString : public Vector<char>
{
private:
    /* data */
public:
    MyString(const char *t, int lo, int hi);
    ~MyString();

    int kmp(const char *s, int len) const;
    int *kmp_build_next(const char *s, int len) const;
};