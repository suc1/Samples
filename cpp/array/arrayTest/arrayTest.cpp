// arrayTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  https://mp.weixin.qq.com/s/-V7d3XUMqsrcDu_CWZP7bg

#include <iostream>
using namespace std;

//1. 数组求和
int Sum0(int* a, int len) {
    //if (len <= 0) return 0;
    //if (len == 1) return a[0];

    //return Sum0(a, len - 1) + a[len - 1];
    return len <= 0 ? 0 : Sum0(a, len - 1) + a[len - 1];
}

void Sum() {
    int a[] = { 1,2,3,4,5 };
    int len = sizeof(a) / sizeof(a[0]);
    int i = Sum0(a, len);
    cout << i << endl;
}

//2. 数组的最大值和最小值
//void MaxandMin(int *a, int l, int r, int& maxValue, int& minValue)
void MinMax0(int* a, int len, int& _min, int& _max) {
    if (len <= 0) return;
    if (len == 1) {
        if (a[0] < _min) _min = a[0];
        if (a[0] > _max) _max = a[0];
        return;
    }

    int mid = len / 2;
    MinMax0(a, mid, _min, _max);
    MinMax0(&a[mid], len-mid, _min, _max);
}

void MinMax() {
    int a[] = { 3,1,5,4,2 };
    int len = sizeof(a) / sizeof(a[0]);
    int _min = a[0], _max = a[0];
    MinMax0(a, len, _min, _max);
    cout << _min << ',' << _max << endl;
}

//3. 最大值和次大值
//ToDo: 处理最大元素有多个的情况
void _Max12(int* a, int len, int& max1, int& max2) {
    for (int i = 0; i < len; ++i) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] > max2) {
            max2 = a[i];
        }
    }
}
void Max12() {
    int a[] = { 3,1,5,4,2 };
    int len = sizeof(a) / sizeof(a[0]);
    int max1, max2;
    if (a[1] > a[0]) {
        max1 = a[1];
        max2 = a[0];
    }
    else {
        max1 = a[0];
        max2 = a[1];
    }

    _Max12(&a[2], len-2, max1, max2);
    cout << max1 << ',' << max2 << endl;
}

//4. 求数组中出现次数超过一半的元素
//One solution: keymap
//先对数组排序，然后取中间元素

//下面的算法可以理解，但是不好证明
int _Repeat(int* a, int n) {
    int curValue = a[0];
    int count = 1;

    for (int i = 1; i < n; ++i)
    {
        if (a[i] == curValue)
            count++;
        else
        {
            count--;
            if (count < 0)
            {
                curValue = a[i];
                count = 1;
            }
        }
    }

    return curValue;
}
void Repeat() {
    int a[] = { 3,1,1,3,3 };
    int len = sizeof(a) / sizeof(a[0]);
    
    cout << _Repeat(a, len) << endl;
}

//5. 求数组中元素的最短距离 -> 最小差值
//6. 两个有序数组的共同元素
//7. 求三个数组的共同元素
//8. 找出数组中唯一的重复元素
//9. 找出出现奇数次的元素
//10. 求数组中满足给定和的数对
//11. 最大子段和 : !!!!
//12. 最大子段积
//13. 数组循环移位       a[(i+k)%n]
//14. 字符串逆序         原地逆序
//15. 组合问题           回溯法
//16. 合并两个数组
//17. 重排问题
//18. 找出绝对值最小的元素    二分搜索法
int main()
{
    //Sum();
    //MinMax();
    //Max12();
    Repeat();
}
