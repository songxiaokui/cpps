//
// Created by 宋晓奎 on 2024/1/15.
//

#ifndef CLASS_MULTIINHERIT_H
#define CLASS_MULTIINHERIT_H

#endif //CLASS_MULTIINHERIT_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// 多继承
// 定义方式
// 成员函数屏蔽问题(重载)与作用域访问
// 菱形继承问题
// 解决菱形继承的virtual虚继承使用
// 虚继承的原理(vbptr vbtable)
// 访问类的内存布局问题
namespace MultiInherit
{
    class Base
    {
    public:
        string name;
    };

    // 解决菱形继承问题 使用虚继承
    class A: virtual public Base
    {
    public:
        void say()
        {
            cout << "this is A" << endl;
        }

        void say(int a)
        {
            cout << "this is A int" << a << endl;
        }

        void no()
        {
            cout << "no" << endl;
        }
    };

    class B: virtual public Base
    {

    };

    class C: public A, public B
    {
    public:
        void showName(void);

        void say(string data)
        {
            cout << "this is reload say " << data << endl;
        }
    };

    void testMultiInherit();
}