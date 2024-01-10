//
// Created by 宋晓奎 on 2024/1/10.
//

#ifndef CLASS_INHERIT_H
#define CLASS_INHERIT_H

#endif //CLASS_INHERIT_H

#include <string>
#include <iostream>

using namespace std;

namespace Inherit {
    void testInherit(void);

    // 定义
    // class 派生类名: 继承类型 基类
    // 定义基类
    class Bass {
    public:
        string type = "基类";

        void showType();

    protected:
        int age = 10;

        void showAge();

    private:
        string password = "123";

        void showPassword();

    };

    // 公共继承
    class Person : public Bass {
    public:
        void sayHello();
    };

    // 私有继承
    class Dog : private Bass {
    public:
        void sayHello();
    };

    // 保护继承
    class Fish : protected Bass {
    public:
        void sayHello();
    };
}
