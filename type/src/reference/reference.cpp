//
// Created by 宋晓奎 on 2023/12/8.
//

#include "reference.h"

void increment(int& a);
void increment(int& a)
{
    a++;
}

int& increment2(int& f);
int& increment2(int& f)
{
    f *= 2;
    return f;
}


void testReference(void)
{
    cout << "this is reference test..." << endl;

    int a(10);
    int& b = a;
    cout << "a = " << a << endl;
    cout << "a的引用b = "<< b << endl;
    cout << "a 的地址" << &a << endl;
    cout << "a的引用b的地址 = "<< &b << endl;

    int c(100);
    b = c;
    cout << "c的地址: " << &c << endl;
    cout << "a的值为: " << a << endl;
    cout << "b引用的值为: " << b << endl;
    cout << "b引用的值的地址为: " << &b << endl;
    // 说明引用初始化后 指向的地址不会在进行更新

    c= 101;
    cout << "a的值为: " << a << endl;
    cout << "b引用的值为: " << b << endl;
    // b在初始化后 地址不变了 虽然b赋值了c 但是c的改变不会影响a和b

    // 引用作为参数
    int d = 1;
    int& e = d;
    increment(e);
    increment(e);
    increment(e);
    cout << "d = " << d<< endl;

    // 通过引用传递函数返回值
    int f = 10;
    int& g = increment2(f);
    cout << "f = " << f << endl;
    cout << "g = " << g << endl;

}