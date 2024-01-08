//
// Created by 宋晓奎 on 2024/1/8.
//

#ifndef CLASS_THISPOINTER_H
#define CLASS_THISPOINTER_H

#include "cstring"
#include "iostream"

using namespace std;


class thispointer {
public:
    string name;
    int age;
    float *fl;
    mutable int t;

    thispointer();

    thispointer(int age, float *x);

    ~thispointer();

    thispointer(const thispointer &p);

    void setAge(int age);

    thispointer &add(thispointer &tp);

    // 定义常函数
    void say() const;
};


#endif //CLASS_THISPOINTER_H

void testThisPointer(void);


namespace Friend {
    class P {

    public:
        string name = "sxk";
    private:
        int password = 123456;
    protected:
        int age = 12;

    public:
        P();

        ~P();

        friend void displayFriend(const P &p);
    };

    void displayFriend(const P &p);

    // 使用类作为友元类
    class A {
        // 在A中定义友元类的引用
        friend class B;

    private:
        string name = "友元";
    };

    class B {
        // 在B中定义实现友元函数的定义
    public:
        class A b;

        void display(const A &a) {
            cout << "类实现友元函数访问A的私有变量:" << a.name << endl;
        }

        void visit() {
            cout << "类实现友元函数访问A的私有变量:" << b.name << endl;
        }
    };

    // 使用类的成员函数实现友元函数
    class C;

    class D {
    public:
        // D有一个成员类为C 想访问C的私有属性
        class C *c;
        void disPlay2();
        D();

    };

    class C {
        friend void D::disPlay2();

    private:
        int age = 1;
    public:
        C();
    };
}