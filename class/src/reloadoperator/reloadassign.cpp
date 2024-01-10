//
// Created by austsxk on 2024/1/9.
//

#include "reloadassign.h"

namespace ReloadAssign {
    Person::Person() {
        this->age = 10;
        this->money = new double(10);
    }

    Person::Person(int age, double money) {
        this->age = age;
        this->money = new double(money);
    }

    Person::Person(const Person &p) {
        cout << "走默认拷贝构造" << endl;
        this->age = p.age;
        this->money = new double(*p.money);
    }

    Person::~Person() {
        if (this->money != nullptr) {
            delete this->money;
            this->money = nullptr;
        }
    }

    Person &Person::operator=(const Person &p) {
        if (this->money != nullptr) {
            delete this->money;
            this->money = nullptr;
        }
        this->age = p.age;
        this->money = new double(*p.money);
        return *this;
    }

    void Person::disPlay() {
        cout << "age=" << this->age << " money=" << *this->money << endl;
    }

    void testReloadAssign(void) {
        Person p1(10, 1.1);
        Person p2 = p1;
        p1.disPlay();
        p2.disPlay();

        Person p3;
        p3 = p2 = p1;
        p3.disPlay();
    }
}