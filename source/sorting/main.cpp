/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-07 16:57:05
 * @LastEditors: yanxinhao
 * @Description: 
 */
#include "sorting/bubblesort.h"
#include"sorting/input.h"
#include"sorting/output.h"
using namespace std;
int main(){
    int A[10]={0};

    show_array(A,10);
    get_input(A,10);
    cout<<"input array :";
    show_array(A,10);

    // bubblesort
    bubblesort(A,10);
    cout<<"output array :";
    show_array(A,10);
    return 0;
}