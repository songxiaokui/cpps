//
// Created by 宋晓奎 on 2024/1/10.
//

#include "reloadcompare.h"

namespace ReloadCompare {

    Person::Person() {

    }

    Person::Person(string name, int age) : name(name), age(age) {

    }

    Person::~Person() {

    }

    void Person::disPlay() {
        cout << "name=" << this->name << " age=" << this->age << endl;
    }

    // 重载判断相等
    bool Person::operator==(const Person &p) const {
        if (this->name == p.name && this->age == p.age) {
            return true;
        }
        return false;
    }

    // 重载判断不相等
    bool Person::operator!=(const Person &p) const {
        if (this->name == p.name && this->age == p.age) {
            return false;
        }
        return true;
    }

    string Person::operator()() const {
        string a = string("详细信息: ") + string("姓名: ") + string(this->name) + string("年龄: ") + (to_string)(this->age);
        return a;
    }

    void testReloadCompare(void) {
        cout << "reload compare test" << endl;
        using namespace ReloadCompare;
        Person p1("Tommy", 19);
        Person p2("Tommy", 19);
        if (p1 == p2) {
            cout << "p1 is equal p2" << endl;
        }

        if (p1 != p2) {
            cout << "p1 is not equal p2" << endl;
        } else {
            cout << "p1 is equal p2" << endl;
        }

        // 重载函数调用符号()
        cout << p1() << endl;
        cout << p2() << endl;
    }
}