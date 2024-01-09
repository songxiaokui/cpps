//
// Created by 宋晓奎 on 2024/1/8.
//

#ifndef CLASS_RELOADOPERATOR_H
#define CLASS_RELOADOPERATOR_H

#endif //CLASS_RELOADOPERATOR_H

#include <string>
#include <iostream>
#include "leftmove.h"
#include "increment.h"
#include "reloadassign.h"

using namespace std;

namespace ReloadOperator
{
    class Person
    {
    public:
        // 重载+
        Person operator+(Person& a);
        // 重载<<
        ostream& operator<<(ostream& out); // p << cout;
        int m_num1;
    };

}

void testReloadOperator(void);