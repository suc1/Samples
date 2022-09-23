// FunctionPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.zhihu.com/question/504164592/answer/2636932453
//!!!!!!!!重大疑问: C++ std::function没法比较callback函数指针是否相等，但是C的函数指针是可以的。Why??????
//! 直接使用C callback弱点是什么


#include <iostream>

////1. 函数指针
int add(int x, int y) {
    return x + y;
}
int sub(int x, int y) {
    return x - y;
}
void main1()
{
    int (*fun)(int x, int y);
    //第一种写法
    fun = add;
    printf("(*fun)(5, 3) = %d, (fun)(5, 3) = %d, fun(5, 3) = %d\n", (*fun)(5, 3), (fun)(5, 3), fun(5, 3));

    //第二种写法
    fun = &sub;
    printf("(*fun)(5, 3) = %d, (fun)(5, 3) = %d, fun(5, 3) = %d\n", (*fun)(5, 3), (fun)(5, 3), fun(5, 3));
}

////2. 回调函数
void myPrintInt(void* data)
{
    int* num = (int*)data;
    printf("%d\n", *num);
}
//提供一个打印函数，可以打印任意类型的数据
void printText(void* data, void(*myPrint)(void*))
{
    myPrint(data);
}
void main2()
{
    int a = 10;
    printText(&a, myPrintInt);
}

//// 3. 回调函数处理数组
//提供一个函数，实现可以打印任意类型的数组 
void printAllArray(void* pArray, int eleSize, int len, void(*myPrint)(void*))
{
    char* p = (char*)pArray;
    for (int i = 0; i < len; i++)
    {
        //获取数组中每个元素的首地址
        char* eleAddr = p + eleSize * i;
        //printf("%d\n", *(int *)eleAddr);
        //交还给用户做打印操作
        myPrint(eleAddr);
    }
}

//// 4. 利用回调函数 提供查找功能


void main3()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    int len = sizeof(arr) / sizeof(int);
    printAllArray(arr, sizeof(int), len, myPrintInt);
}



int main()
{
    //main1();
    //main2();
    main3();

    return 0;
}
