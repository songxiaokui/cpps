//
// Created by 宋晓奎 on 2023/12/22.
//

#include "classbuildfuntion.h"

class Person1 {
public:
    // 无参数构造函数
    Person1() {
        cout << "这是无参数构造函数调用" << endl;
    }

    Person1(int i) {
        cout << "这是有参构造函数调用" << endl;
        age = i;
    }

    Person1(int i, int d) {
        age = i;
        address = new int(d);
    }

    Person1(const Person1 &x) {
        cout << "这是自定义拷贝构造函数调用" << endl;
        age = x.age;  // 注意 = 语句默认为浅拷贝 把所有的东西复制到新对象上 包括指针
        // 避免浅拷贝 使用深拷贝 自己申请内存空间
        address = new int(*x.address);
    }

    // 初始化参数列表
    Person1(int a, int b, int c) : a(a), b(b), c(c) {
        age = 1;
        address = new int(0);
    }

    ~Person1() {
        if (this->address == nullptr) {
            delete this->address;
            this->address = nullptr;
        }
        cout << "这是析构函数的调用" << endl;
    }

    int age;
    int *address;
    int a;
    int b;
    int c;
};

void buildFunction(void) {
    cout << "类的构造函数" << endl;
    // 1. 类的构造函数与析构函数
    // 与类同名的函数为 构造函数
    // 参数为 const 类名& 的构造函数为 拷贝构造函数
    // ~类名() 的函数为析构函数
    // 构造函数支持重载
    // 类默认提供了无餐构造函数 默认拷贝构造函数 析构函数
    // 构造函数在初始化对象时默认调用 析构函数在对象离开作用域时被调用 进行资源释放
    // 只要定义一个类 默认提供了空实现的无参构造函数 拷贝构造函数(浅拷贝所有成员变量) 析构函数(空实现)

    // 2. 类构造函数初始化的三种方式
    // 括号法
    // 显示声明法
    // 隐式转换法

    // 括号法
    // 无参数
    Person1 p1;
    // 有参数
    Person1 p2(10);
    // 拷贝构造
    Person1 p3(p2);
    cout << "p3的age:" << p3.age << endl;
    // 注意: 不要直接使用 Person1 p1(); 该方法表示的是函数声明语句

    // 显示声明
    // 无参数
    Person1 p4 = Person1();
    // 有参数
    Person1 p5 = Person1(10);
    // 拷贝构造
    Person1 p6 = Person1(p5);
    // 注意: Person1(p5) 是一个无地址的临时对象 在声明行调用 在声明行执行结束就自动释放 其作用域只在当前行

    // 隐式转换
    // 有参数 等价为有参显示声明 ==> Person1 p7 = Person1(10);
    Person1 p7 = 10;
    // 拷贝构造 等价为拷贝构造的显示声明 == > Person1(p7)
    Person1 p8 = p7;


    // 3. 拷贝构造函数的调用时机
    // 使用已有对象进行新对象初始化
    // 值传递做函数参数
    // 值传递做函数返回值
    // 总结一句话就是: 只要开辟新空间的复制 就会调用拷贝构造函数

    // 4. 浅拷贝与深拷贝
    // C++中默认的赋值语句都是浅拷贝
    // 如果需要深拷贝 需要自己重新在堆上申请内存空间 否则可能会出错

    // 5. 默认构造函数与自定义构造函数定义及关联
    // 只要定义一个类 默认会生成一个无参数构造函数(空实现) 析构函数(空实现) 拷贝构造函数(所有的属性进行浅拷贝)
    // 若 自定义有参构造函数 则不再提供无参数构造函数 但是会提供拷贝构造函数
    // 若 自定义拷贝构造函数 则不再提供无参构造函数和析构函数

    // 6. 类初始化列表使用
    // 其本质是是使用了括号赋值
    // 给构造函数定义如下:
    // Person(int a, int b, int c): 属性a(a), 属性b(b), 属性c(c) {} 括号中可以做其他的事
    Person1 p9(1, 2, 4);
}