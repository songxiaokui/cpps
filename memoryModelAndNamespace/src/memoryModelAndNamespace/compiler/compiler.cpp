//
// Created by 宋晓奎 on 2023/12/19.
//

#include "compiler.h"

// 在源文件中定义
int this_age = 100;

const string MY_NAME = "sss";
static string MY_NAME_2 = "aaa";
string MY_NAME_3 = "sxk";

// 静态存储持续性
// 1. 外部链接性定义
int out_link_var = 10;
// 2. 内部链接性定义
static int inner_link_var = 11;

// 内部变量
// int INNER_STATIC = 1000;  // 会报错 重复定义
static int INNER_STATIC = 9999;

void owner_func()
{
    cout << "这是全局函数" << endl;
}

void Compiler(void) {
    cout << "This is compile file ." << endl;
    // 程序拆分三部分
    // 头文件: 包含结构的声明和函数原型
    // 源代码文件: 包含与结构有关的函数的代码
    // 源代码文件: 包含调用与结构相关的函数的代码

    // 注意: 不要将函数定义(函数实现)和变量声明放到头文件中
    // 头文件中包括的内容:
    //      函数原型
    //      使用宏define定义或const定义的符号常量
    //      结构声明
    //      类声明
    //      模版声明
    //      内联函数

    // 使用预处理指令#include时 需要注意下面两点
    //  1. 如果文件名在<>内部 则C++编译器将在存储标准头文件的主机系统的文件系统中查找
    //  2. 如果时自定义的头文件 则使用""包裹引入的头文件名称即可 编译器首先查找当前工作目录或源代码目录

    // 预处理指令
    // #define
    // #ifndef #endif
    cout << SXK << endl;
    cout << sxk << endl;

    // 翻译单元
    // 名称修饰: 在C++中，函数名和变量名在编译后会发生名称修饰，这是为了支持函数重载和命名空间的特性，用来区分编译后不同的函数或变量

    // C++存储模式
    // 自动存储持续性: 在函数内部声明的变量、函数参数的存储位自动(随函数调用而分配内存 函数执行结束 内存释放)
    // 静态存储持续性: 在函数外定义的全局变量 和使用关键词static定义的变量，或使用const定义的全局常量 在程序整个运行过程中都存在
    // 线程存储持续性: 在多核处理器上，使用thread_local声明,其生命周期和所属线程一样长
    // 动态存储持续性: 使用new运算符分配的内存一直存在，直到使用delete运算符将其释放或程序结束 （自由存储 堆存储）

    // 作用域
    // scope 描述的名称在文件(翻译单元)的范围可见性

    // 链接性
    // linkage 描述了名称如何在不同文件(翻译单元)间共享
    // 链接性为外部的名称可以在文件间共享
    // 链接性为内部的名称只能在一个文件内共享
    // 自动变量的名称没有链接性 所以不能共享

    {
        int a = 1;
        cout << "局部代码块: " << a << endl;
    }
    // cout << a << endl; // error 局部外不可见

    // 综上: C++存储方式是通过存储连续性、作用域、链接性描述

    // auto现在都在后置类型推断中使用
    // 在C以前老版本用来指定自动变量
    int auo = 1;
    cout << "Out a address: " << &auo << endl;
    {
        // use auto 创建自动变量
        // auto int auo = 100;
        cout << "Inner a address: " << &auo << endl;
    }
    cout << "auo: " << auo << endl;

    // 自动变量的初始化
    // 可以使用任何在声明时其值为已知的表达式来初始化自动变量

    // 自动变量与栈
    // 程序执行时有两个栈帧 一个栈底 一个栈顶
    // 调用函数时 将参数按顺序押入栈顶 栈顶指针按类型移动
    // 然后将押入栈的数据与形参关联
    // 当在函数内执行遇到自动变量 栈顶继续移动分配内存
    // 程序执行结束 栈顶指针回到函数调用处 等于释放内存

    // 寄存器变量
    // 关键词register定义 它建议编译器使用CPU寄存器来存储自动变量
    // 目的是为了提高访问变量的速度

    // 静态存储持续性
    // 三种情况
    //      1. 外部链接性(可以在其他文件中访问 全局变量)
    //      2. 内部链接性(只能在当前文件内访问)
    //      3. 无链接性(只能在当前函数或代码块内访问)
    //      静态存储是分配的一块存储区 由程序运行时分配 声明周期直到程序运行结束

    // 定义
    // 1. 外部链接性 (在代码块外部定义)
    // 2. 内部链接性 (使用static修饰变量 并定义在代码块外部)
    // 3. 无链接性 (使用static修饰变量 并定义在代码块内部)
    // 示例
    {
        // 无链接性
        static int null_link_var = 10;
        // 输出访问域及存储
        cout << "静态外部链接性: " << out_link_var << " 其地址: " << &out_link_var << endl;
        cout << "静态内部链接性: " << inner_link_var << " 其地址: " << &inner_link_var << endl;
        cout << "静态无链接性: " << null_link_var << " 其地址: " << &null_link_var << endl;
        /*
         *
         *  静态外部链接性: 10 其地址: 0x1007f0000
            静态内部链接性: 11 其地址: 0x1007f0008
            静态无链接性: 10 其地址: 0x1007f0004
         */
        // 由此可见: 静态存储变量 是划分在一个固定区域段的内存 与动态存储持续性不同
    }

    // 静态存储持续性的特征: 未被初始化的静态变量所有位都被设置位0，这也叫零初始化

    // 静态变量的初始化
    // 1. 零初始化
    // 2. 常量表达式初始化
    // 3. 动态初始化

    // 静态变量的初始化流程
    // 1. 先使用零初始化
    // 2. 然后如果常量表达式初始化该变量 编译器将根据文件内容计算表达式 执行常量表达式初始化
    // 3. 如果没有足够大信息 变量将动态初始化

    // C++11 支持 constexpr初始化静态变量
    {
        static constexpr int my_int = 2 * 10;
        cout << "this is constexpr initialized: " << my_int << endl;
    }

    // constexpr 创建常量表达式方式
    constexpr double my_float = 11 * 3.1415;
    cout << "my_float: " << my_float << endl;

    // 全局变量(静态外部链接性变量)
    // 在外部使用文件中 都必须声明该变量
    // 另外 根据单定义规则 变量只能定义一次
    // C++变量声明方式有以下2种:
    //      1. 定义声明: 会给变量分配存储空间 简称定义
    //      2. 引用声明: 不会给变量分配存储空间 只是引用已有变量 使用关键词 extern 不进行初始化，否则成定义

    // ⚠️注意:
    //      尽量不要在头文件中定义外部链接性变量(全局变量)
    //      因为如果在头文件中定义外部变量 当该头文件被预处理指令引用多次时 就会产生变量重复定义 从而违背变量的单定义规则
    // 定义最佳实现:
    //      在头文件中只做声明, 在源码文件中定义
    //      例如: 现在有a.h、a.cpp, b.h, b.cpp
    //          先在在b.cpp中需要使用a源码文件定义的全局变量
    //          则在 a.h中声明: extern int a_f;
    //          在 a.cpp中定义: int a_f = 100;
    //          在 b.h中使用该源文件 需要使用#include "a.h"
    //          在 b.h中声明使用的变量: extern int a_f;
    //          在 b.cpp中使用全局变量: cout << a_f << endl;

    // 总之: 遵循外部变量只有一个定义 其他全部声明

    // 输出全局变量的值
    cout << "-----------------------------------" << endl;
    cout << "全局变量HIDE_NUMBER: " << HIDE_NUMBER << endl;
    // 更新全局变量
    my_update(HIDE_NUMBER);
    // 输出全局变量
    cout << "在代码卡内更新 全局变量HIDE_NUMBER: " << HIDE_NUMBER << endl;
    // 输出局部变量
    local();

    // local中: 自动变量隐藏了同名全局变量 自动变量的链接性只在函数体内
    // update中: 使用extern type name可以重新定义全局变量 修改后的值 全局可见 作用域为所有文件

    // 静态持续性-内部链接性
    // cout << INNER_STATIC << endl; // 会报错 重复定义
    // static 限定了变量定义只在当前文件内可见 无法访问到其他文件的该同名变变量
    cout << INNER_STATIC << endl;
    cout << ::INNER_STATIC << endl;
    showInnerStatic();

    // 使用外部变量实现多个文件中的数据共享
    // 使用内部变量可以实现同一个文件中多个函数之间数据共享

    // 静态持续性-无链接性
    // 使用static限定符号 在代码卡内部定义的变量
    // 生命周期: 程序运行期间
    // 作用域: 代码块或函数体内

    // 存储说明符号
    //      auto : 自动变量 或 后置类型推断说明 使用 auto f(...) -> decltype(x+y);
    //      register : 建议编译器将数据存储到寄存器中
    //      static : 根据上下文意义不一样, 在代码卡外部,表示静态持续性-内部链接性；在代码块内部定义, 表示静态持续性-无链接性变量
    //      extern : 通常用来声明一个全局变量或引用一个全局变量 通常告诉编译器 不用进行内存分配
    //      thread_local : 在多核CPU中 定义线程局部变量 生命周期随线程而生 线程死而亡
    //      mutable : 用于类中声明成员变量 他允许变量在const成员函数中进行修改

    // mutable 示例如下
    class MyMutable a1;
    a1.name = "sxk";
    a1.age = 18;
    a1.update(a1, "张三");

    // c-v限定符号
    //      const: 内存被初始化后,程序不能对它进行修改
    //      volatile: 告诉编译器，不要对该变量进行优化。它的值会受到程序之外的控制而改变
    //      volatile的使用场景: 1. 多线程或中断环境 确保每次取值都是从内存中取出最新
    //                        2. IO操作 当变量表示设备寄存器与内存地址映射时,其值会受到程序外的控制而改变

    // mutable 用来说明类或结构成员变量即使受const限定也可以修改
    const struct data d1 = {"sxk", 18, 10};
    // age不可被修改 d1时const限定不能修改
    // d1.age++;  // 会报错
    d1.access++; // 不会报错 因为mutable说明 所以可以修改

    // 限定符号 const 深度剖析
    // 默认情况下 全局变量是 静态持续性 外部链接性
    // 但是 const定义的全局变量 是内部链接性
    // 定义等价于: static xxxx;
    // 通常: 将const定义的常量定义在头文件中
    // 最后的实质是引用了该头文件的文件 都有一组常量 而不是共享一组常量

    // compiler.h
    cout << "compiler in NAM1 address: " << &NAME1 << endl;
    // myconst.h
    showAddress();
    // 结果如下:
    // compiler in NAM1 address: 0x100d6fe68
    // File myconst.h NAME1 address: 0x100d6fe80
    // 综上所述: const定义的变量为内部链接性 所以不会产生重复定义的问题

    // 使用extern 可以将常量的链接性改成外部链接
    cout << "extern const var address: " << &NAME5 << endl;
    showInnerAddress();
    // 结果输出:
    //  extern const var address: 0x102453e80
    //  Extern Inner link var address: 0x102453e80
    // 在头文件中使用extern const type name;声明常量外链接常量 可以和全局变量类似

    // 函数和链接性
    functionLink();
    // owner_func();  // 此处报错 owner_func() 是内部函数 不可导出
    // 与内部函数同名
    owner_func();

    // 语言链接性
    language_call(10);
    sayHello();
    my_add(1.1, 2.3333);

}