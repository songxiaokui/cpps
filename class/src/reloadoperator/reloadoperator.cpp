//
// Created by 宋晓奎 on 2024/1/8.
//

#include "reloadoperator.h"

namespace ReloadOperator {
    Person Person::operator+(Person &a) {
        Person temp;
        temp.m_num1 = this->m_num1 + a.m_num1;
        return temp;
    }
}

ReloadOperator::Person operator+(ReloadOperator::Person& p,  int a)
{
    using namespace ReloadOperator;
    Person temp;
    temp.m_num1 = p.m_num1 + a;
    return temp;
}

void testReloadOperator(void) {
    ReloadOperator::Person p1;
    ReloadOperator::Person p2;
    p1.m_num1 = 10;
    p2.m_num1 = 20;
    ReloadOperator::Person p3 = p1.operator+(p2);
    ReloadOperator::Person p4 = p1 + p2;
    cout << "p3 is: " << p3.m_num1 << endl;
    cout << "p4 is: " << p4.m_num1 << endl;

    int a = 1000;
    ReloadOperator::Person p5 = p1 + a;
    cout << "p5 is: " << p5.m_num1 << endl;
}