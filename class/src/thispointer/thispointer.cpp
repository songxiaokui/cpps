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

void testThisPointer(void) {
    cout << "class model and this pointer..." << endl;

    float *x = new float(1.1);
    thispointer p1(10, x);
    thispointer p2(20, x);
    // 链式调用
    p2.add(p1).add(p1).add(p1);
    //如果不返回引用 在触发默认拷贝构造是 会开辟新的空间地址进行赋值 就不会在返回的对象上继续调用
    cout << "p2 age is: " << p2.age << endl;
}