//
// Created by 宋晓奎 on 2024/1/9.
//

#ifndef CLASS_LEFTMOVE_H
#define CLASS_LEFTMOVE_H

#endif //CLASS_LEFTMOVE_H
#include <string>
#include <iostream>
using namespace std;

namespace LeftMove
{
    class Person
    {
        // 全局函数访问私有属性，定义友元函数
        friend ostream& operator<<(ostream& out, const Person& p);
    public:
        Person(int a): age(a)
        {

        }
    private:
        int age;
    };

    void testLeftMove(void);
}

