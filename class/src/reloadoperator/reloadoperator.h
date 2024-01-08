//
// Created by 宋晓奎 on 2024/1/8.
//

#ifndef CLASS_RELOADOPERATOR_H
#define CLASS_RELOADOPERATOR_H

#endif //CLASS_RELOADOPERATOR_H

#include <string>
#include <iostream>

using namespace std;

namespace ReloadOperator
{
    class Person
    {
    public:
        Person operator+(Person& a);
        int m_num1;
    };

}

void testReloadOperator(void);