//
// Created by 宋晓奎 on 2024/1/8.
//

#include "thispointer.h"

void thispointer::setAge(int age) {
    this->age = age;
    this->fl = new float(3.14);
}

thispointer &thispointer::add(thispointer &tp) {
    this->age += tp.age;
    return *this;
}

thispointer::thispointer() {
    this->fl = new float(3.14);
}

thispointer::thispointer(int age, float *x) {
    this->age = age;

    float *f = new float(*x);
    this->fl = f;
}

thispointer::~thispointer() {
    cout << "对象被析构了" << endl;
    if (this->fl != nullptr) {
        delete this->fl;
    }

}

void thispointer::say() const
{
    if (this == nullptr)
    {
        cout << "this is null" << endl;
        return;
    }
    // this->age = 100; // 会报错，不可修改
    // mutable 修饰的成员变量可以被修改
    this->t = 100;
    cout << "常函数调用" << endl;
}

void Friend::displayFriend(const P &p)
{
    cout << "共有属性name: " << p.name << endl;
    cout << "私有属性password: " << p.password << endl;
    cout << "保护属性age: " << p.age << endl;
}

Friend::P::P(){}

Friend::P::~P() {}

void Friend::D::disPlay2(const C &c) {
    cout << "类成员函数实现友元函数访问C的私有变量: " << c.age << endl;
}

void testThisPointer(void) {
    cout << "class model and this pointer..." << endl;

    float *x = new float(1.1);
    thispointer p1(10, x);
    thispointer p2(20, x);
    // 链式调用
    p2.add(p1).add(p1).add(p1);
    //如果不返回引用 在触发默认拷贝构造是 会开辟新的空间地址进行赋值 就不会在返回的对象上继续调用
    cout << "p2 age is: " << p2.age << endl;

    // 常对象
    const thispointer p(1, x);
    // 只能调用常函数
    p.say();
    // 不能调用普通函数
    // p.add(p1); // 会报错

    // 空对象调用类函数 this为空指针
    thispointer* p3 = nullptr;
    p3->say();

    // 全局函数实现友元函数
    Friend::P p4;
    Friend::displayFriend(p4);
    // 类成员实现友元函数
    Friend::A a1;
    Friend::B b1;
    b1.display(a1);
    // 在一个类中实现友元函数
    Friend::C c1;
    Friend::D d1;
    d1.disPlay2(c1);

}