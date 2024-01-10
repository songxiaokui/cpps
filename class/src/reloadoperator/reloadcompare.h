//
// Created by 宋晓奎 on 2024/1/10.
//

#ifndef CLASS_RELOADCOMPARE_H
#define CLASS_RELOADCOMPARE_H

#endif //CLASS_RELOADCOMPARE_H

#include <iostream>
#include <string>

using namespace std;

namespace ReloadCompare
{
    class Person
    {
    public:
        string name;
        int age;
        Person();
        Person(string name, int age);
        ~Person();
        void disPlay();
        // 重载判断相等
        bool operator==(const Person& p);
        // 重载判断不相等
        bool operator!=(const Person& p);
        // 重载调用 泛用性更高 可多样化函数签名与返回值类型
        string operator()();
    };

    void testReloadCompare(void);
}