//
// Created by 宋晓奎 on 2024/1/9.
//

#ifndef CLASS_INCREMENT_H
#define CLASS_INCREMENT_H

#endif //CLASS_INCREMENT_H
#include <iostream>
#include <string>
using namespace std;

namespace Increment
{
    void testIncrement(void);

    class Person
    {
        // 友元函数
        friend ostream& operator<<(ostream& out, const Person& p);
    public:
        Person(int a);
        Person();
        Person(const Person& p); // 默认拷贝构造函数
        ~Person();
    private:
        int m_A;
    public:
        // 前置自增 返回引用可进行链式调用
        Person& operator++();
        // 后置自增 不返回引用
        const Person operator++(int);
        // 前置递减
        Person& operator--();
        // 后置递减
        const Person operator--(int);
        //
    };

    // 重载<<左移运算符
    ostream& operator<<(ostream& out, const Person& p);
}