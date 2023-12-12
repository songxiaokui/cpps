//
// Created by 宋晓奎 on 2023/12/12.
//

#include "reference.h"

inline void swap_pointer(int* a, int* b);
inline void swap_pointer(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

inline void swap_reference(int& a, int& b);
inline void swap_reference(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void testReference(void)
{
    cout << "this capture is reference..." << endl;
    cout << "引用: 就是已定义变量的别名" << endl;
    cout << "引用的用途: 用作函数的形参,使得函数在调用时不用进行大数据的拷贝操作，直接进行原始数据的访问与修改操作，特别方便函数处理大型结构" << endl;

    // 1. 引用变量的创建
    // 使用 [限定词const] 变量类型& 变量名 = 被引用变量;
    int ra(10);
    const int& rra = ra;
    cout << "rra = " << rra << endl;
    cout << "ra = "<< ra << endl;
    // rra = 100; // 不能通过引用修改数据
    ra = 100;
    cout << "rra = " << rra << endl;
    // int& 是指向int的引用

    // 2. 引用与指针的区别
    // 引用必须在声明时进行初始化 指针可以先声明，再赋值
    // 引用一旦初始化 后续不会再进行更改 其地址一直是初始化变量的地址
    // 类似与指针常量(指针的指向不能更新)
    // int& r = b ==> int* const ptr = &b;

    int rc(101);
    int& rrc = rc;
    int rb(999);
    rrc = rb;
    rb = 9;
    cout << "rrc = " << rrc << endl;
    cout << "rc = " << rc << endl;
    cout << "rb = " << rb << endl;

    cout << "rrc address = " << &rrc << endl;
    cout << "rc address = " << &rc << endl;
    cout << "rb address = " << &rb << endl;
    // 由此可见  rrc = rb; 虽然没报错 只是起了赋值操作 将rb的值赋值给了rrc 从而使得rc发生更新

    // 3. 将引用作为函数参数
    // 这种方式称为: 按引用传递
    // 使用这种方式: 实现了将函数的形参成为了实参的别名，也就是引用
    int a = {100};
    int b = {200};
    cout << "交换前: a = " << a << " b = " << b << endl;
    // 使用指针实现两个数据交换
    swap_pointer(&a, &b);
    cout << "第一次交换后: a = " << a << " b = " << b << endl;

    // 使用引用实现两个数据交换
    swap_reference(a, b);
    cout << "第二次交换后: a = " << a << " b = " << b << endl;

}