//
// Created by 宋晓奎 on 2023/12/19.
//

#include "namespace.h"

namespace {
    float t1 = 1.111;
    void f1();

    void f1()
    {
        cout << "未命名命名空间函数调用 f1() " << endl;
    }
}

void fetch();
void fetch()
{
    cout << "this is global fetch() calling" << endl;
}


char pail[] = "global pail";



void usingNameSpace();
void usingNameSpace()
{
    Jill::fetch();
    Jack::fetch();
    // 全局作用域函数调用
    ::fetch();

    cout << "Jill:pail = " << Jill::pail << endl;
    cout << "Jack:pail = " << Jack::pail << endl;
    cout << "Global::pail = " << ::pail << endl;

}

void localVariableSubstitution(void);
void localVariableSubstitution(void)
{
    cout << "global variable pail is: " << pail << endl;  // is equal ::pail
    using Jill::pail;
    cout << "local variable substitution: pail is: " << pail << endl;
}

// 名称空间嵌套与名称空间使用using编译指令和using声明
namespace N1 {
    namespace N2 {
        string name = "sxk in N2";
        using std::cout;
        using std::endl;
        using ::fetch;
        using namespace Jack;
    }
    string name = "sxk in N1";
}

namespace T3
{
    string name = "sxk";
}

namespace T2
{
    using namespace T3;
}

namespace T1
{
    using namespace T2;
}



void Namespace(void)
{
    cout << "This is namespace file ." << endl;
    // 概念理解
    // 1. 声明区域（可以在其中声明的区域）（全局变量的声明区域为所有变量，自动变量的声明区域在当前所在代码块）
    // 2. 潜在作用域（从声明开始一致到声明区域结束）
    // 3. 作用域（变量对程序可见的范围为作用域，同名变量隐藏区域不是作用域）

    // 定义命名空间的函数与变量
    usingNameSpace();
    // 命名空间可以是全局的 也可以位于另一个命名空间 但不能在代码块中
    // 默认情况下 名称空间内声明的名称为外部链接性
    // 全局名称空间：文件级别声明 全局变量就是全局名称空间
    // 使用名称空间的内容: 使用作用域解析运算符 ::


    // using声明与using编译指令
    // 目的: 简化对名称空间内名称的使用
    // using声明: 声明就是使指定的标识符可用
    // using编译指令: 使整个名称空间可用
    localVariableSubstitution();

    // using编译指令的使用:
    // 使用 using namespace 名称空间;
    using namespace Jill;
    // cout << "Jill namespace pail: " << pail << endl;  // 产生二义性
    // 与 ::pail 产生冲突 不知道是使用 Jill中的pail 还是使用全局中的pail
    // 正确使用: 增加作用域解析运算符 指定明确的命名空间
    cout << "Jill::pail: " << Jill::pail << endl;
    cout << "Global::pail: " << ::pail << endl;

    // 注意: 如果一个名称已经在代码块中声明 则不能再使用using 声明进行该名称的声明
    /*
    int pail;
    using Jill::pail;
    using Jack::pail;

     // 上述代码会报错
    */

    {
        using namespace Jill;
        // 局部变量会隐藏全局pail与Jill命名空间下的pail
        double pail = 1.11;
        cout << "pail: " << pail << endl;
        // 使用作用域解析运算符 可以正常使用全局pail和指定名称空间下的pail
        cout << "Global pail:" << ::pail << endl;
        // Jill::pail
        cout << "namespace variable use: " << Jill::pail << endl;
    }

    // 通常来说: 使用using声明比using 编译指令安全,using声明只导入了指定的名称

    // using编译指令注意的问题:
    // 1. using namespace 名称空间;放在代码卡内，名称空间的所有名称只在代码块生效
    // 2. using namespace 名称空间; 放在全局名称名称空间,方便但是容易被局部变量隐藏
    // 3. 尽量使用 作用域解析运算符方式使用或者使用using 声明只引入需要的名称

    // 名称空间的特性
    // 1. 名称空间嵌套
    // 2. 在名称空间中使用using编译指令与using声明
    // 3. using 编译指令可传递
    // 4. 名称空间可以创建别名

    // 1. 名称空间嵌套
    N1::N2::cout << "名称空间嵌套:" << N1::name << N1::N2::endl;

    // 2. 在名称空间中使用using编译指令与using声明
    using namespace N1::N2;
    cout << "N2::fetch() calling: " << N1::N2::name << endl;
    N1::N2::fetch();

    // 3. using 编译指令可传递
    // 若 N1 包括 N2、N2 包括 N3；则N1 包括 N3
    {
        using namespace T1;
        // 等价与 using namespace T2 和 using namespace T3
        cout << "T1 name is equal T2 name or T3 name: " << T1::name << endl;
        using namespace T3;
        cout << "T3 name is: " << T3::name << endl;
    }

    // 4. 名称空间可以创建别名
    {
        namespace my_name = N1::N2;
        cout << "namespace alias:" << my_name::name << endl;
        using my_name::name;
        cout << "using declaration variable:" << name << endl;
    }

    cout << "name is : " << name << endl;

    // 未命名的命名空间
    // 未命名的命名空间的名称-潜在作用域为从声明点到声明区域末尾
    // 未命名的命名空间的名称 不能使用using声明或using编译指令显示声明使用
    // 未命名的命名空间的名称 链接性为内部 和静态变量类似
    {
        // 只能在当前文件内部调用
        f1();
        cout << "未命名变量： " << t1 << endl;
        // 局部变量覆盖
        double t1 = 9.9999;
        cout << "t1 is: " << t1 << endl;
    }

}