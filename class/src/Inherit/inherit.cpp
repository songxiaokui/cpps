//
// Created by 宋晓奎 on 2024/1/10.
//

#include "inherit.h"

namespace Inherit
{
    void Bass::showType() {
        cout << "type is " << this->type << endl;
    }

    void Bass::showAge() {
        cout << "age is " << this->age << endl;
    }

    void Bass::showPassword() {
        cout << "password is " << this->password << endl;
    }

    void Person::sayHello() {
        cout << "人类打招呼: 你好" << endl;
    }
    void Fish::sayHello() {
        cout << "鱼类打招呼: 。。。" << endl;
    }

    void Dog::sayHello() {
        cout << "狗类打招呼: 汪汪汪" << endl;
    }

    void testInherit(void)
    {
        cout << "inherit class" << endl;
        // 类的好处
        // 减少重复代码量
        Person p1;
        Fish f1;
        Dog d1;

        p1.showType();
        p1.sayHello();
        f1.sayHello();
        d1.sayHello();

        // 不同类型继承,对基类成员变量和基类成员函数的访问权限不同
        // 公共类型
        // 子类中父类的成员变量、成员函数的访问权限不变

        // 保护类型
        // 子类中父类的public权限变成protected, 其他权限不变

        // 私有权限
        // 子类中父类的public权限、protected权限都变成私有权限
    }
}