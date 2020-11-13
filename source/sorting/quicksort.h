/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-11-13 21:38:06
 * @LastEditors: yanxinhao
 * @Description: 
 */
// 思路有一个空闲单元在lo和hi两个位置来回交换,空闲单元的位置最终就是pivot的位置
// 因为将lo位置的元素作为pivot,所以第一个空闲位置在lo位置
template <typename T>
int partion(T *arr, int lo, int hi)
{
    T pivot = arr[lo];
    while (lo < hi)
    {
        // 从hi位置开始比较,hi位置值大于等于pivot时将hi归入R
        while ((lo < hi) && (pivot <= arr[hi]))
            hi--;
        arr[lo] = arr[hi]; //此时空闲位置转到hi位置

        // lo位置的值比pivot小时,将lo归入L部分
        while ((lo < hi) && (arr[lo] <= pivot))
            lo++;
        arr[hi] = arr[lo]; //此时空闲位置转到hi位置}
    }
    // assert lo==hi
    arr[lo] = pivot;
    return lo;
}

template <typename T>
void quicksort(T *arr, int lo, int hi)
{
    // 设置递归基,要特别注意最小的问题的条件不是想当然的 hi-lo == 1.因为可能会出现hi==lo的情况
    // if (hi - lo == 1 || hi - lo == 0)
    if (hi - lo < 2)
        return;
    int posi_pivot = partion(arr, lo, hi - 1);
    quicksort(arr, lo, posi_pivot);
    quicksort(arr, posi_pivot + 1, hi);
}
