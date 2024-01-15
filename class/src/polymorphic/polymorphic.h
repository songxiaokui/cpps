//
// Created by austsxk on 2024/1/15.
//

#ifndef CLASS_POLYMORPHIC_H
#define CLASS_POLYMORPHIC_H

#endif //CLASS_POLYMORPHIC_H
#include <string>
#include <iostream>
using namespace std;
namespace Polymorphic
{
    class Base
    {
    public:
        virtual void say();
    };
    class A: public Base
    {
    public:
        void say();
    };

    class B: public Base
    {
    public:
        void say();
    };

    // 抽象类与纯虚函数
    class VirtualBase
    {
    public:
        virtual int getData() = 0;
        int m1;
        int m2;
    };

    class Add: public VirtualBase
    {
    public:
        int getData();
    };

    class Sub: public VirtualBase
    {
    public:
        int getData();
    };

    class Multi: public VirtualBase
    {
    public:
        int getData();
    };

    class Div: public VirtualBase
    {
    public:
        int getData();
    };
    void testPolymorphic(void);
}
