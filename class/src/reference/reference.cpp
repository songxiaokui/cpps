//
// Created by 宋晓奎 on 2023/12/12.
//

#include "reference.h"

inline void swap_pointer(int* a, int* b);
inline void swap_pointer(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

inline void swap_reference(int& a, int& b);
inline void swap_reference(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

double cube(const double& a)
{
    return a * a * a;
}

struct FreeThrows
{
    std::string name;
    std::string brand;
    double price;
    int attempts;
};

void showFreeThrows(const FreeThrows& f)
{
    // f.name = "sss"; // const 限定词修饰 不支持修改
    cout << "name: " << f.name << " brand: "
        << f.brand << " price: " << f.price
        << " attempts: " << f.attempts << endl;
}

void updateFreeThrows(FreeThrows& f, double price)
{
    f.price = price;
}

struct FreeThrows& accumulate(FreeThrows& target, const FreeThrows& source)
{
    cout << "in functions target address: " << &target << endl;
    target.price += source.price;
    target.attempts += target.attempts;
    showFreeThrows(target);
    return target;
}

struct FreeThrows& clone(FreeThrows& f)
{
    auto ptr = new FreeThrows {};
    *ptr = f;
    return *ptr;

}

const struct FreeThrows& clone2(FreeThrows& f)
{
    auto ptr = new FreeThrows {};
    *ptr = f;
    return *ptr;

}

void file_out(ostream& os, int count, const char*& s)
{
    for (int i = 0; i< count; i++)
    {
        os << s << endl;
    }
}

void testReference(void)
{
    cout << "this capture is reference..." << endl;
    cout << "引用: 就是已定义变量的别名" << endl;
    cout << "引用的用途: 用作函数的形参,使得函数在调用时不用进行大数据的拷贝操作，直接进行原始数据的访问与修改操作，特别方便函数处理大型结构" << endl;

    // 1. 引用变量的创建
    // 使用 [限定词const] 变量类型& 变量名 = 被引用变量;
    int ra(10);
    const int& rra = ra;
    cout << "rra = " << rra << endl;
    cout << "ra = "<< ra << endl;
    // rra = 100; // 不能通过引用修改数据
    ra = 100;
    cout << "rra = " << rra << endl;
    // int& 是指向int的引用

    // 2. 引用与指针的区别
    // 引用必须在声明时进行初始化 指针可以先声明，再赋值
    // 引用一旦初始化 后续不会再进行更改 其地址一直是初始化变量的地址
    // 类似与指针常量(指针的指向不能更新)
    // int& r = b ==> int* const ptr = &b;

    int rc(101);
    int& rrc = rc;
    int rb(999);
    rrc = rb;
    rb = 9;
    cout << "rrc = " << rrc << endl;
    cout << "rc = " << rc << endl;
    cout << "rb = " << rb << endl;

    cout << "rrc address = " << &rrc << endl;
    cout << "rc address = " << &rc << endl;
    cout << "rb address = " << &rb << endl;
    // 由此可见  rrc = rb; 虽然没报错 只是起了赋值操作 将rb的值赋值给了rrc 从而使得rc发生更新

    // 3. 将引用作为函数参数
    // 这种方式称为: 按引用传递
    // 使用这种方式: 实现了将函数的形参成为了实参的别名，也就是引用
    int a = {100};
    int b = {200};
    cout << "交换前: a = " << a << " b = " << b << endl;
    // 使用指针实现两个数据交换
    swap_pointer(&a, &b);
    cout << "第一次交换后: a = " << a << " b = " << b << endl;

    // 使用引用实现两个数据交换
    swap_reference(a, b);
    cout << "第二次交换后: a = " << a << " b = " << b << endl;

    // 4. 引用传递
    // 其传递的要求更加严格
    // 值传递: 可以传表达式 函数调用 字面量 变量 等
    // 引用传递: 只能传变量 引用就是给变量起别名 所以函数的形参传递的实参只能是变量
    // 如果不想通过引用修改实参 可以加限定词 const 修饰

    // 早期版本
    // 可以兼容 int& ra => a + 10;
    // 实质: 编译器创建了一个临时变量存 a + 10 然后将ra指向临时变量的引用

    // 临时变量、引用参数、const
    // 临时变量创建时间: 实参与引用参数不匹配 C++将生成临时变量 当前阶段只有加了const限定词才会
    // 创建临时变量的条件:
    //      1. 实参的类型正确 但不是左值(左值: 可以被引用的数据对象，变量、数组、结构、指针等，除了字面量常量及多项表达式)
    //      2. 实参的类型不正确，但可以转换为正确的类型
    double side = {10};
    double* sidep = &side;
    double& sider = side;
    long size1 = {5L};
    double* arr = new double [5] {1.0, 2.0, 3.0, 4.0, 5.0};

    double c1 = cube(side); // 引用a->side 不会创建临时空间
    double c2 = cube(*sidep); // 引用a->sidep的解引用 不会创建临时空间
    double c3 = cube(sider); // 应用a->sider->side
    double c4 = cube(arr[1]); //数组的元素行为与同类型变量一致
    double c5 = cube(static_cast<double>(size1)); // 类型不一致 强制转换
    double c6 = cube(1.0); // 字面量常量 创建临时变量
    double c7 = cube(side + 2.0); // 表达式 创建临时变量
    // 引用尽可能的使用const
    // 理由：
    // 1. const 避免数据被无意间修改
    // 2. 使用const能处理const 和非const的实参
    // 3. const引用能够使函数正确的生成临时变量

    // 右值引用
    // C++11引入的引用类型
    // 支持移动语义和完美转发 通过&&声明
    // 支持我们引用临时对象(右值)
    // 移动语义: 将一个对象移动到另外一个对象 而不是使用传统的复制
    // 完美转发: 允许在不转变类型的方式将参数传递给其他函数

    double&& rref = std::sqrt(36.0); // double& 将报错
    cout << "rref: " << rref << endl;

    double j {101.1};
    double&& rr2 = j * 3.14 + 2;
    cout << "rr2: " << rr2 << endl;

    // 5. 引用与结构
    struct FreeThrows f = {"冰箱", "格力", 3599.99, 2019};
    showFreeThrows(f);
    updateFreeThrows(f, 1000);
    // 返回引用
    struct FreeThrows f2 = {"洗衣机", "美的", 1299.01, 2088};
    struct FreeThrows& f3 = accumulate(f2, f);
    cout << "f2 address: " << &f2 << endl;
    cout << "f3 address: " << &f3 << endl;
    showFreeThrows(f3);

    accumulate(f2, f) = f;
    showFreeThrows(f2); // 引用没变 只是 引用地址的值对象已经更新为f对象的值罢了

    // 为什么要返回引用
    // 传统的返回:
    //      将结果复制到寄存器或者开辟新的内存空间将结果复制于此 由编译器告知函数调用者计算结果存储的位置 然后函数调用者将结果复制到接受变量
    //      从概念上来说: 就是值复制到一个临时位置
    // 返回引用：
    //      其实质应该是创建了一个常量指针 给team起别名 应该不是进行对象的复制
    //      typeName* const 变量名 =  &返回对象名；

    // 返回引用需要注意的问题?
    // 1. 不要返回函数内部局部变量的内存单元引用(不要返回栈空间数据)
    //      解决方案: 1. 将返回的结果通过引用参数进行传递到函数内部
    //               2. 通过使用new 关键词声明结果对象 将数据分配在堆空间 这样函数调用内存释放不会产生非法内存地址访问
    struct FreeThrows ftr = {"sxk", "国产", 10e9, 100};
    const FreeThrows& newFtr = clone(ftr);
    cout << "ftr address: " << &ftr << endl;
    cout << "after clone address: " << &newFtr << endl;
    // clone 出来的对象记得释放
    // clone 实际得到是新对象的引用
    delete &newFtr;

    // 右值: 不能通过地址访问的值 如字面量值(不包括字符串)、表达式
    // 左值: 能够通过地址访问的值
    // 常规函数返回的都是右值，这种返回值存在于临时内存单元中 执行下一条指令时 就不存在了
    // 使用const限定词修饰引用返回值
    // 可以防止引用值被修改
    // 形式
    // const typeName& functionName(params...);

    // 不加const
    clone(ftr) = f;  // 可以修改
    // 加const
    // clone2(ftr) = f; // 报错
    // 返回类型为const限定 时不可修改的左值 所以不合法

    // 将引用用于类对象
    // const引用形参最典型的属性:
    //      若实参类型不匹配形参，但是实参类型可以转换为形参类型，则程序会创建一个正确的临时变量
    //    将转换后的实参值初始化改变量 然后传递指向该临时变量的引用

    // 对象、继承、引用
    // 继承: 能够将特性从一个类传递给另一个类的语言特性 叫继承

    // ofstream 创建文件与写入的标准库
    const char* fileName = "./show.txt";
    std::ofstream outputFile(fileName);
    if (outputFile.is_open())
    {
        outputFile << "Hello world" << endl;
        outputFile << "C++ is interesting" << endl;
        // outputFile.close();
    }
    else
    {
        cout << "File " << fileName  << " is not opened!" << endl;
    }

    // use cout
    const char* s = "sxk";
    file_out(cout, 10, s);
    // use file
    file_out(outputFile, 10, s);
    // close file
    outputFile.close();
    cout << "文件具柄已关闭" << endl;

    ios_base::fmtflags initFlag;
    initFlag = cout.setf(ios_base::fixed);
    cout.setf(initFlag);
    cout.precision(4);
    cout << 2.4 << endl;
}