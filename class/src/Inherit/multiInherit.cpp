//
// Created by 宋晓奎 on 2024/1/15.
//

#include "multiInherit.h"

namespace MultiInherit
{
    void C::showName() {
        // 产生二义性 继承了2个那么 一个A 一个B 但是这个name都是来自基类
        // cout << "我的名字: " << this->name << endl;

        // 只能通过作用域访问
        cout << "A: 我的名字: " << this->A::name << endl;
        cout << "B: 我的名字: " << this->B::name << endl;
    }

    void testMultiInherit()
    {
        C c;
        c.A::name = "sxk";
        c.B::name = "ddd";
        c.showName();

        // 正常来说 继承只应该右一个name 不应该有多个name
        // 所以要解决菱形继承问题 需要使用虚继承 virtual

        // 虚继承的原理
        // 根据vsd 工具ci查看内存布局可知
        // cl /d1 reportSingleClassLayoutYourC "multiInherit.h"
        // A类和B类的内存中没有字段 存了一个指针 vbptr 其指向的是一个序地址表 vbtable
        // vbtable存储的函数和成员变量的偏移量
        // 根据vbptr的地址 + 对应成员的偏移量
        // 就可以找到存储在类中的唯一一个成员变量的存储地址
        // 这样就可以保证 从基类继承的成员变量只有一份

        /*
        虚继承：
            虚继承是指在派生类中使用 virtual 关键字来声明对基类的继承。
            当一个类以虚方式继承另一个类时，它将共享基类的子对象，以避免在多重继承中出现重复的基类实例。
            虚继承的一个典型应用场景是解决菱形继承（diamond inheritance）问题，即通过虚继承可以避免由于多层继承而导致的二义性和资源浪费。
            在虚继承中，派生类只继承了虚基类的一个实例，而不是多次复制。

        虚函数表（vtable）：
            虚函数表是 C++ 中实现多态性的关键机制之一。
            当一个类中包含虚函数时，编译器会为该类生成一个虚函数表，其中存储了指向各个虚函数的指针。
            每个含有虚函数的类都有自己的虚函数表。
            当对象被实例化时，会在对象的内存布局中添加一个指向虚函数表的指针（通常称为 vptr）。
            通过 vptr 和 vtable，C++ 实现了动态绑定，使得在运行时能够正确调用相应的虚函数，实现多态性。
         */

        // 注意
        // 只有派生类重载类基类的同名函数 那么只能通过作用域来访问父类的方法
        c.no();
        // 下面找不到基类的方法 因为重载 只能用作用域访问
        // c.say();
        // c.say(10);
        c.A::say();
        c.A::say(10);

        // 派生类访问无影响
        c.say("hello");
    }
}