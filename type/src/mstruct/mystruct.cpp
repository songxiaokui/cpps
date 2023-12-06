//
// Created by 宋晓奎 on 2023/12/5.
//

#include "mystruct.h"
#include <string>
#include <vector>

struct Person {
    std::string Name;
    int Age;
    std::string Hobby[5];
    std::vector<std::string> Brother;
};

void testStruct() {
    using namespace std;
    cout << "this is struct files test" << endl;

    // 定义结构体
    // 使用结构体
    struct Person xMing = {
            .Name= "朱小明",
            .Age = 19,
            .Hobby = {"打篮球", "唱歌", "跑步"},
            .Brother = {"小刚", "小李"}

    };

    cout << "xMing的名字: " << xMing.Name << endl;
    cout << "xMing的年龄: " << xMing.Age << endl;

    for (const auto &hobby: xMing.Hobby) {
        cout << hobby << endl;
    };

    for (const auto &brother: xMing.Brother) {
        cout << brother << endl;
    };

    // C++11 花括号初始化
    struct Person p1{"sxk", 18};
    // 其他字段为零值

    // 结构对象赋值 等于给每个成员赋值
    p1 = xMing;
    cout << "p1的名字: " << p1.Name << endl;
    cout << "p1的年龄: " << p1.Age << endl;

    // 定义并赋值
    struct P2 {
        std::string Name;
        int Age;
    } p3 = {
            .Name= "b",
            .Age=2,
    },
            p4 = {
            .Name= "a",
            .Age=1,
    };
    cout << "p3.name = " << p3.Name << endl;
    cout << "p3.age = " << p3.Age << endl;

    // 还可以去掉结构名称 匿名结构 但是只能使用一次

    // 定义成员函数
    struct P3 {
        std::string Name;

        // 声明是常量函数
        void sayHello() const {
            std::cout << "hello " << this->Name << endl;
        };
    };

    struct P3 p5{"sxk"};
    p5.sayHello();

    // 结构数组
    struct P3 arrayStruct[2] = {
            {"小明"},
            {"小李"},
    };

    for (const auto &a: arrayStruct) {
        a.sayHello();
    }

    // 结构中的位字段
    // 通俗的说给每个字段分配固定的位数
    // 目的为了匹配寄存器
    // 我的理解也是为了内存对齐
    struct torgleRegister {
        unsigned int Number: 4;
        char : 4; // 不使用 只站位
        bool goodIn: 1;
        bool GD: 1;
    };

    torgleRegister tr = {10, false, true};
    cout << "tr.Number = " << tr.Number << endl;
    cout << "tr.goodIn = " << tr.goodIn << endl;
    cout << "tr.GD = " << tr.GD << endl;
};