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

    ostream& Person::operator<<(ostream& out)
    {
        out << "在类内重载<<: " << this->m_num1;
        return out;
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

    // cout << p1 << endl; // 如果不重载<<则报错 如果用类实现
    p1.operator<<(cout); // 没办法丝滑私用 cout << p1;这种形式
    cout << endl;

    // 使用全局函数方式重载<< 左移动运算符
    LeftMove::testLeftMove();

    // 自增运算符重载
    Increment::testIncrement();

    // 重载赋值运算符
    ReloadAssign::testReloadAssign();

    // 重载比较运算符
    ReloadCompare::testReloadCompare();
}