//
// Created by 宋晓奎 on 2023/12/11.
//

#include "main.h"

void func(...);
void func(int a, int b)
{
    cout << a+b << endl;
}

int main() {
    cout << "this is class module..." << endl;

    // bass
    //  testCircle();

    // cube
    // testCube();

    // func(1,3);

    // testLimits();

    // testFunc();

    // reference
    // testReference();

    // 构造函数
    // buildFunction();

    // this指针
    // testThisPointer();

    // 运算符重载
    // testReloadOperator();

    // 继承
    // Inherit::testInherit();
    MultiInherit::testMultiInherit();
    return 0;
}
