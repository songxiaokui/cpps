//
// Created by austsxk on 2024/1/15.
//

#include "polymorphic.h"

namespace Polymorphic
{
    // 如果不是定义虚类和虚函数 需要对基类的虚函数进行实现 否则会报错
    void Base::say() {
        cout << "this is base" << endl;
    }

    void A::say() {
        cout << "this is A" << endl;
    }

    void B::say() {
        cout << "this is B" << endl;
    }

    // 纯抽象类与纯虚函数
    int Add::getData() {
        return this->m1 + this->m2;
    }
    int Sub::getData() {
        return this->m1 - this->m2;
    }
    int Multi::getData() {
        return this->m1 * this->m2;
    }
    int Div::getData() {
        return this->m1 / this->m2;
    }

    void testPolymorphic(void)
    {
        cout << "多态模块" << endl;
        Base* b = new A();
        b->say();
        delete b;

        b = new B();
        b->say();
        delete b;

        b = new Base();
        b->say();
        delete b;

        cout << "抽象类与纯虚函数" << endl;
        VirtualBase* vb = new Add();
        vb->m1 = 100;
        vb->m2 = 2;
        cout << vb->m1 << "+" << vb->m2 << "=" << vb->getData() << endl;
        delete vb;

        vb = new Sub();
        vb->m1 = 100;
        vb->m2 = 2;
        cout << vb->m1 << "-" << vb->m2 << "=" << vb->getData() << endl;
        delete vb;

        vb = new Multi();
        vb->m1 = 100;
        vb->m2 = 2;
        cout << vb->m1 << "*" << vb->m2 << "=" << vb->getData() << endl;
        delete vb;

        vb = new Div();
        vb->m1 = 100;
        vb->m2 = 2;
        cout << vb->m1 << "/" << vb->m2 << "=" << vb->getData() << endl;
        delete vb;

    }
}