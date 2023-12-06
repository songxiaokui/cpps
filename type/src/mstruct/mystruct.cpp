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

    // 共用体
    // 允许在同一内存位置存储不同的数据类型
    // 共用体中的所有成员共享同一块内存，因此共用体的大小等于其最大成员的大小
    // 定义
    union One4all {
        int int_value;
        float float_value;
        double double_value;
    };

    One4all a{};
    a.double_value = 12.1;
    a.int_value = 1;
    a.float_value = 1.11;
    cout << a.float_value << endl;
    cout << a.int_value << endl;
    cout << a.double_value << endl;

    // 匿名且无中间变量时 联合体字段就是结构的一部分
    struct P4 {
        char type;
        int id;
        union {
            int int_value;
            float float_value;
        };
    };

    P4 p6{};
    if (p6.type == '1')
    {
        p6.int_value = 1;
    }
    else
    {
        p6.float_value = 1.1;
    }
    // int_value 和 float_value 共用内存，且没有中间对象变量 就成为了P4的成员变量
    // 用途: 共用体通常用来操作系统结构或硬件数据结构
    
};