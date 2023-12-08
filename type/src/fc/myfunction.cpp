//
// Created by 宋晓奎 on 2023/12/7.
//

#include "myfunction.h"

int add(int a, int b) {
    return a + b;
}

void swap(int a, int b) {
    int temp(a);
    a = b;
    b = temp;
}

void testFunctions(void) {
    cout << "this is functions file test..." << endl;

    // callback
    cout << "1 + 3 = " << add(1, 3) << endl;

    // 值传递
    // 函数的形参在函数内发生改变 并不会影响外部的实参
    int a = 10;
    int b = 20;
    cout << "交换前: a=" << a << " b=" << b << endl;
    swap(a, b);
    cout << "交换前: a=" << a << " b=" << b << endl;

    // pointer
    int *pt1 = static_cast<int *>(std::malloc(sizeof(int)));
    int *pt3 = new int;
    int pt(10);

    *pt1 = pt;
    cout << "pt1 = " << *pt1 << endl;
    // 释放内存
    std::free(pt1);
    cout << "pt1 = " << *pt1 << endl;
    *pt1 = 103;
    cout << "pt1 = " << *pt1 << endl;
    std::free(pt1);
    cout << "pt1 = " << *pt1 << endl;

    *pt3 = pt;
    cout << "pt3 = " << *pt3 << endl;
    delete pt3;  // 释放内存
    cout << "pt3 = " << *pt3 << endl;

    int x = 101;
    int *pt4 = &x;
    cout << "pt4= " << *pt4 << endl;
    // delete pt4; // 进程已结束,退出代码134 (interrupted by signal 6: SIGABRT)
    // std::free(pt4); // 进程已结束,退出代码134 (interrupted by signal 6: SIGABRT)
    cout << "ok" << endl;

    // 数组
    int arr[10] = {0,};
    cout << "静态数组的长度: " << sizeof arr << endl;

    // 动态数组
    int *da = new int[20];
    cout << "动态数组的长度: " << sizeof da << endl; // 8 注意 不是输出的20,动态数组返回的是指针的长度
    cout << "动态数组第一个元素: " << da[0] << endl;
    cout << "动态数组第二个元素: " << da[1] << endl;
    cout << "动态数组第三个元素: " << da[2] << endl;
    cout << "动态数组第四个元素: " << da[3] << endl;
    for (int i = 0; i < 20; i++) {
        cout << "数据：" << da[i] << endl;
    }

    // 赋值
    da[11] = 101;
    cout << "释放前: " << da[11] << endl;

    // 释放内存
    delete[] da;
    cout << "释放后: " << da[11] << endl;

    // 指针不是整数
    int *pt5 = new int;
    // pt5 = &101;// 不可以
    int a1 = 101;
    pt5 = static_cast<int *>(&a1);
    cout << "pt5= " << *pt5 << endl;

    // 指针运算
    int arr2[10] = {0, 1};
    cout << "arr2[0]=" << arr2[0] << endl;
    cout << "arr2[1]=" << (arr2 + 1)[0] << endl;

    // 数组与指针
    int arr5[10] = {1, 2, 3, 4, 5};
    int *pint = arr5;
    int *pint2 = &arr5[0];
    cout << "arr[5]的地址: " << arr5 << endl;
    cout << "pint的地址: " << pint << endl;
    cout << "pint2的地址: " << pint2 << endl;
    // 对数组的加减和指针的加减法效果相同
    cout << *(arr5 + 1) << endl;
    cout << *(pint + 1) << endl;
    cout << *(pint2 + 1) << endl;

    cout << "---" << endl;
    cout << "arr5 对数组取地址: " << &arr5 << endl;
    cout << "arr5 的地址: " << arr5 << endl;
    cout << "arr5[0]号元素的地址: " << &arr5[0] << endl;

    short* p[20] = {}; // short类型的指针数组
    short (*p1)[20] = {}; // 长度为20的short数组 指针 类型 short (*)[20]

    // 解引用
    int* py = new int [10];
    *py = 5;
    py[0] = 1;
    py[8] = 100;
    *(py+2) = 100;

    int* py2;
    py2 = py;
    py2[7] = 9;

    cout << "py[7] = " << py[7] << endl;
    delete [] py;

    // C字符串
    char st[10] = {'a', 't', 'i', 'l', '\0'}; // 以空字符结尾 否则不能区分
    cout << "st = " << st << endl;

    char st2[20] = "attila"; // 默认自动补全\0
    cout << "st2 = " << st2 << endl;

    char* st3 = st;
    cout << "st3: " << (int*) st3 << endl;  // 只要是 字符串数组 指针 引号括起来的字符串 都是将第一个字符的地址发送给cout对象
    cout << "st3: " << static_cast<const void*>(st3) << endl;  // 只要是 字符串数组 指针 引号括起来的字符串 都是将第一个字符的地址发送给cout对象

    int* in1 = new int;
    *in1  = 100;
    cout << "in1 address " << static_cast<const void*>(in1) << endl;
    delete in1;

    cout << "st length = " << strlen(st) << endl;  // strlen 不包括\0空字符

    char* st4;
    st4 = new char [strlen(st)+1]; // 必须要包含空字符的长度 否则不构成字符串
    strcpy(st4, st);

    cout << "st4 after copy is " << st4 << endl;
    delete [] st4;

    // 函数类型 4种
    // 无返回值 无参数
    // 无返回值 有参数
    // 有返回值 无参数
    // 有返回值 有参数
    // 函数声明的好处
}

