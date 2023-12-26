//
// Created by 宋晓奎 on 2023/12/19.
//

#ifndef MEMORYMODELANDNAMESPACE_NAMESPACE_H
#define MEMORYMODELANDNAMESPACE_NAMESPACE_H

#endif //MEMORYMODELANDNAMESPACE_NAMESPACE_H

#include <iostream>
#include "define2.h"
#include "../using/definition.h"

using namespace std;

namespace Student
{
    static int MAX_LENGTH = 10;
    using namespace std;
    class Std
    {
    public:
        string name;
        int xh;
        void show();

        Std();
        ~Std();
    };
}

void Namespace(void);

namespace MyPerson {
    using namespace Student;

    class Person {
    public:
        std::string name;
        int age;
        Std* studentList;
        int count;
        // 静态成员属性
        // 静态属性 类内定义 类外初始化
        // 整个类共享数据
        static int total;

        Person(std::string name, int age);

        Person();

        ~Person();

        Person(const Person &);

        void show();

        static int get_total();

        void addStudent(const Std& st);

        void showStudent();



    private:
        void increment();
    };
}

