//
// Created by austsxk on 2024/1/9.
//

#ifndef CLASS_RELOADASSIGN_H
#define CLASS_RELOADASSIGN_H

#endif //CLASS_RELOADASSIGN_H

#include <string>
#include <iostream>

using namespace std;

namespace ReloadAssign
{
    class Person
    {
    private:
        int age;
        double* money;
    public:
        Person();
        Person(int age, double money);
        Person(const Person& p);
        ~Person();
        void disPlay();
        Person& operator=(const Person& p);
    };

    void testReloadAssign(void);
}