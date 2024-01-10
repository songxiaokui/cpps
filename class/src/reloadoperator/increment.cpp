//
// Created by 宋晓奎 on 2024/1/9.
//

#include "increment.h"

void Increment::testIncrement() {
    int a = 1;
    cout << ++a << endl; // 2
    cout << a << endl;  // 2

    int b = 1;
    cout << b++ << endl; // 1
    cout << b << endl; // 2

    using namespace Increment;
    Person p1(10);
    cout << ++p1 << endl;
    cout << p1 << endl;

    Person p2(10);
    cout << p2++ << endl;
    cout << p2 << endl;

    cout << --p1 << endl;
    cout << p1 << endl;

    cout << p2-- << endl;
    cout << p2 << endl;

}

Increment::Person::Person(int a) : m_A(a) {};

Increment::Person &Increment::Person::operator++() {
    // 前置 先++ 再返回
    this->m_A++;
    return *this;
}

const Increment::Person Increment::Person::operator++(int a) {
    Increment::Person temp(this->m_A);
    this->m_A++;
    return temp;
}

ostream &Increment::operator<<(ostream &out, const Person &p) {
    out << "--> " << p.m_A << endl;
    return out;
}

// 前置递减
Increment::Person &Increment::Person::operator--() {
    this->m_A--;
    return *this;
}

// 后置递减
const Increment::Person Increment::Person::operator--(int) {
    Increment::Person temp(this->m_A);
    this->m_A--;
    return temp;
}

Increment::Person::Person() {
    this->m_A = 0;
}

Increment::Person::Person(const Person &p) {
    this->m_A = p.m_A;
}

Increment::Person::~Person() {

}