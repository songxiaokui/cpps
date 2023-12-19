//
// Created by 宋晓奎 on 2023/12/12.
//

#include "reference.h"
#include <cmath>

inline void swap_pointer(int *a, int *b);

inline void swap_pointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

inline void swap_reference(int &a, int &b);

inline void swap_reference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

double cube(const double &a) {
    return a * a * a;
}

struct FreeThrows {
    std::string name;
    std::string brand;
    double price;
    int attempts;
};

void showFreeThrows(const FreeThrows &f) {
    // f.name = "sss"; // const 限定词修饰 不支持修改
    cout << "name: " << f.name << " brand: "
         << f.brand << " price: " << f.price
         << " attempts: " << f.attempts << endl;
}

void updateFreeThrows(FreeThrows &f, double price) {
    f.price = price;
}

struct FreeThrows &accumulate(FreeThrows &target, const FreeThrows &source) {
    cout << "in functions target address: " << &target << endl;
    target.price += source.price;
    target.attempts += target.attempts;
    showFreeThrows(target);
    return target;
}

struct FreeThrows &clone(FreeThrows &f) {
    auto ptr = new FreeThrows{};
    *ptr = f;
    return *ptr;

}

const struct FreeThrows &clone2(FreeThrows &f) {
    auto ptr = new FreeThrows{};
    *ptr = f;
    return *ptr;

}

void file_out(ostream &os, int count, const char *&s) {
    for (int i = 0; i < count; i++) {
        os << s << endl;
    }
}

char *left(char *str, int n) {
    int len = (int) strlen(str);
    n = n > len ? len : n;
    char *newStr = new char[n + 1];
    strncpy(newStr, str, n);
    return newStr;
}

unsigned int left(int a, int n) {
    int raw = a;
    unsigned int digits(1);
    while (a /= 10) {
        digits++;
    }

    cout << "数字: " << raw << " 总共有: " << digits << "位" << endl;

    return n >= digits ? raw : (int) (raw / pow(10, (digits - n)));

}

void add1(int a, int b) {
    cout << "int a + int b = " << a + b << endl;
}

void add1(double a, double b) {
    cout << "double a + double b = " << a + b << endl;
}

void add1(char *a, int a1, char *b, int a2) {
    char *result = (char *) std::malloc(sizeof(char) * (a1 + a2 + 1));
    // char *result = new char[a1 + a2 + 1];
    strcpy(result, a);
    result = &result[a1];
    strcpy(result, b);
    result = &result[-a1];
    cout << "str add: " << result << endl;
    // delete [] result;
    free(result);
}

void sink(double &r1) {
    cout << "double& result: " << r1 << endl;
}

void sank(const double &r2) {
    cout << "const double& result: " << r2 << endl;
}

// 泛型编程
template<typename SxkType>
void Swap(SxkType &a, SxkType &b) {
    SxkType temp = a;
    a = b;
    b = temp;
}

template<class MyType>
void Println(MyType a) {
    cout << a << endl;
}

void sunk(double &&r3) {
    cout << "右值引用, double&& result: " << r3 << endl;
}

template<class T>
void PrintSlice(T *slice, int length) {
    for (int i = 0; i < length; i++) {
        cout << " " << slice[i];
    }
    cout << endl;
}

template<class T>
void DoubleSort(T *slice, int length) {
    cout << "排序前输出: " << endl;
    PrintSlice(slice, length);
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (slice[j] > slice[j + 1]) {
                T temp = slice[j];
                slice[j] = slice[j + 1];
                slice[j + 1] = temp;

            }
        }
    }
    cout << "排序后输出: " << endl;
    PrintSlice(slice, length);
}

template<typename T>
void Swap(T a[], T b[], int length) {
    for (int i = 0; i < length; i++) {
        T temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

template<typename T>
void Swap1(T &a, T &b) {
    cout << "这是普通模版函数Swap1" << endl;
    T temp = a;
    a = b;
    b = temp;
}

template<>
void Swap1<Job1>(Job1 &a, Job1 &b) {
    cout << "这是显示具体化函数Swap1" << endl;
    double temp = a.price;
    a.price = b.price;
    b.price = a.price;
}

void Swap1(int &a, int &b) {
    cout << "这是普通函数Swap1" << endl;
    int temp = a;
    a = b;
    b = temp;
}

template<class T>
void ShowArray(T arr[], int length) {
    cout << "函数特征: T arr[], int length" << endl;
    for (int a = 0; a < length; a++) {
        cout << "a = " << arr[a] << endl;
    }
}

template<class T>
void ShowArray(T *arr[], int length) {
    cout << "函数特征: T* arr[], int length" << endl;
    for (int a = 0; a < length; a++) {
        cout << "a = " << *arr[a] << endl;
    }
}

// 定义的模版
template<typename T>
T my_add(T a, T b) {
    cout << "这是my_add的模版函数" << endl;
    return a + b;
}

// 自定义类型
int my_add(int a, int b) {
    cout << "这是自定义的类型实现" << endl;
    return a + b;
}

void testReference(void) {
    cout << "this capture is reference..." << endl;
    cout << "引用: 就是已定义变量的别名" << endl;
    cout << "引用的用途: 用作函数的形参,使得函数在调用时不用进行大数据的拷贝操作，直接进行原始数据的访问与修改操作，特别方便函数处理大型结构"
         << endl;

    // 1. 引用变量的创建
    // 使用 [限定词const] 变量类型& 变量名 = 被引用变量;
    int ra(10);
    const int &rra = ra;
    cout << "rra = " << rra << endl;
    cout << "ra = " << ra << endl;
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
    int &rrc = rc;
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
    double *sidep = &side;
    double &sider = side;
    long size1 = {5L};
    double *arr = new double[5]{1.0, 2.0, 3.0, 4.0, 5.0};

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

    double &&rref = std::sqrt(36.0); // double& 将报错
    cout << "rref: " << rref << endl;

    double j{101.1};
    double &&rr2 = j * 3.14 + 2;
    cout << "rr2: " << rr2 << endl;

    // 5. 引用与结构
    struct FreeThrows f = {"冰箱", "格力", 3599.99, 2019};
    showFreeThrows(f);
    updateFreeThrows(f, 1000);
    // 返回引用
    struct FreeThrows f2 = {"洗衣机", "美的", 1299.01, 2088};
    struct FreeThrows &f3 = accumulate(f2, f);
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
    const FreeThrows &newFtr = clone(ftr);
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
    const char *fileName = "./show.txt";
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        outputFile << "Hello world" << endl;
        outputFile << "C++ is interesting" << endl;
        // outputFile.close();
    } else {
        cout << "File " << fileName << " is not opened!" << endl;
    }

    // use cout
    const char *s = "sxk";
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

    // 何时使用引用参数
    // 1. 能够在函数内进行数据对象的修改更新
    // 2. 将大对象的值传递改成引用传递 可以提高程序的运行速度

    // 值传递的情况:
    //      1. 只读不写, 数据对象很小如都是内置数据类型或小型结构

    // 指针传递的情况:
    //      1. 只读不写 数据对象是数组 并且声明为const指针
    //      2. 读写并存 数据对象是内置数据类型 使用指针
    //      3. 读写并存 数据对象是数组 只能使用指针
    //      4. 读写并存 数据对象是结构 可以使用指针或引用

    // 引用传递的情况:
    //      1. 只读不写 数据对象是较大的结构 使用 const指针 或者 const 引用 提高程序运行效率和节省空间
    //      2. 只读不写 数据对象是类对象 使用const 引用，类设计的语义常常要求使用引用
    //      3. 读写并存 数据对象是结构 可以使用指针和引用
    //      4. 读写并存 数据对象是类对象 使用引用

    // 函数默认值
    char str1[] = "hello world";
    cout << left(str1, 3) << endl;

    // 函数重载
    add1(1, 2);
    add1(1.0, 2.0);
    char s1[] = "sxk";
    char s2[] = "hello world";
    add1(s1, 3, s2, 11);

    double sd1 = {1.11};
    sink(sd1);
    const double sd2 = {1.12};
    sank(sd2);
    sunk(1.1 + 1.2);
    // 上述三种类型的函数重载，调用将用最匹配的版本
    // 第一个: 正常的左值引用与可修改左值引用
    // 第二个: const左值引用与右值参数
    // 第三个: 右值参数

    // 重载示例
    char stn[] = "sxk hello";
    cout << "字符串: " << left(stn, 3) << endl;
    cout << "数字: " << left(109191, 3) << endl;
    cout << "数字: " << left(333, 5) << endl;

    // 何时使用函数重载
    //  仅当函数基本上执行相同的任务,使用不同形式的数据时,才应用采用函数重载

    // 什么是名称修饰（名称矫正）
    // 编译器根据函数原型中指定的形参类型对每个函数进行加密

    // 函数模版
    // 泛型编程
    // 函数模版是通用的函数描述 泛型可用于具体类型 通过将类型作为参数传递给模版 可以使编译器
    // 生成该类型的函数
    // 定义方式
    // 1. 声明类型 template <typename 自定义类型>
    // 2. 在函数签名中使用 自定义类型
    // 示例
    // 交换两个整型
    int sw1{10};
    int sw2{99};
    cout << "int swap before: " << "sw1: " << sw1 << " sw2: " << sw2 << endl;
    Swap(sw1, sw2);
    cout << "int swap after: " << "sw1: " << sw1 << " sw2: " << sw2 << endl;

    // 交换两个double
    double sdoub1{1.1};
    double sdoub2{9.9};
    cout << "double swap before: " << "sdoub1: " << sdoub1 << " sdoub2: " << sdoub2 << endl;
    Swap(sdoub1, sdoub2);
    cout << "double swap after: " << "sdoub1: " << sdoub1 << " sdoub2: " << sdoub2 << endl;

    // 交换两个char类型
    char ch1 = 'a';
    char ch2 = 'f';
    cout << "char swap before: " << "ch1: " << ch1 << " ch2: " << ch2 << endl;
    Swap(ch1, ch2);
    cout << "char swap after: " << "ch1: " << ch1 << " ch2: " << ch2 << endl;

    // 总结:
    // 1. 建立模版 并给类型命名(关键词 template和typename是必须的 可以使用class代替typename)
    // 2. 必须使用尖括号，类型名称任意选择
    // 3. C++98之前没有加typename  可以使用class替代
    // 4. 使用场景: 需要多个但同种算法的不同类型的函数
    // class 示例如下:
    Println("hello world");
    Println(9.88);
    Println('a');

    // 重载模版
    // 需要多个对不同类型使用同一种算法的函数可以使用模版
    // 如下面的排序算法
    // 对int double char类型排序
    int *sliceInt = new int[]{1, 3, 2, 6, 4, 9, 7, 10, 8};
    char *sliceChar = new char[]{'a', 'f', 'e', 'b', 's', 'z', 'm'};
    double *sliceDouble = new double[]{1.0, 0.9, 3.3, 2.0, 9.8, 200.0, 4.2};
    DoubleSort(sliceInt, 9);
    DoubleSort(sliceChar, 7);
    DoubleSort(sliceDouble, 7);
    delete[] sliceInt;
    delete[] sliceChar;
    delete[] sliceDouble;

    // 上面是所有类型都适合的排序算法
    // 重载模版: 函数签名、函数特征必须不同
    // 与重载函数类型
    // 示例
    int *al1 = new int[]{1, 2, 3, 4, 5, 6, 0};
    int *bl1 = new int[]{7, 8, 9, 10, 11, 12, 13};
    Swap(al1, bl1, 7);
    PrintSlice(al1, 7);
    PrintSlice(bl1, 7);

    int n1 = 10;
    int n2 = 20;
    Swap(n1, n2);
    Println(n1);
    Println(n2);

    delete[] al1;
    delete[] bl1;

    // 函数模版的局限性
    // 同一个模版 无法满足所有类型的所有操作
    // 解决方案:
    //      1. 显示具体化
    // 第三带具体化方案有三种
    // 1. 对于给定的函数名可以使用非模版函数 模版函数 显示具体化模版函数三种
    // 2. 显示具体化的原型和定义使用template <> 打头 并通过名称来指定类型
    // 3. 具体化函数优于常规模版函数 非模版函数优于具体化函数原型
    // 说明:
    // 1. 非模版函数
    // void Swap(typeName a, typeName b);
    // 2. 模版函数
    // template <typename T>
    // void Swap(T a, T b);
    // 具体化函数
    // template<> void Swap<job>(job& a, job& b);
    // 编译器选择原型的顺序: 非模版函数 > 具体化函数 > 模版函数

    // 普通函数(优先)
    int k1 = 10;
    int k2 = 20;
    Swap1(k1, k2);
    cout << "k1= " << k1 << " k2= " << k2 << endl;

    // 显示具体化，具体化函数优先
    struct Job1 job1 = {"Job1", 12, 99.0};
    struct Job1 job2 = {"Job2", 14, 19.0};
    Swap1(job1, job2);
    cout << "Job1.price: " << job1.price << " Job2.price: " << job2.price << endl;

    // 模版函数
    double jk1 = 1.1;
    double jk2 = 9.9;
    Swap1(jk1, jk2);
    cout << "jk1= " << jk1 << " jk2= " << jk2 << endl;

    // 模版函数的实例化与具体化
    // 函数模版本身不会生成函数定义，函数模版只是一个用于生成函数定义的方案
    // 模版实例: 编译器使用模版为特定类型生成函数定义得到的就是模版实例

    // 编译器如何选择使用函数？
    // 函数重载 函数模版 函数模版重载等等
    // 编译器根据参数来决定函数调用行为的过程称为重载解析 overloading resolution
    // 重载解析的过程:
    // 1. 创建候选函数列表，包含与被调函数名称相同的函数与模版函数
    // 2. 使用候选函数列表创建可行函数列表 (隐使转换序列)
    // 3. 确定是否有最近的可行函数 如果有就使用 没有就抛出异常

    // 注意:
    // const 形参只区分与指针和引用数据 不区分(int) (const int) 签名如此就会产生二义性
    // 非模版函数优于模版函数（包括显示具体化）
    // 如果匹配的函数都是模版函数 则比较具体模版函数的优先级别 (显示具体化>模版函数)

    // most specialized 最具体
    // 不一定意味着显示具体化 而是指编译器推断使用哪种类型时执行的转换最少

    // 用于找出最具体的模版的规则被称为函数模版的部分排序规则
    int arrayInt1[] = {1, 3, 5, 7, 9};
    int *arrayPointerInt1[3];
    int ia = 1;
    int ib = 2;
    int ic = 3;
    arrayPointerInt1[0] = &ia;
    arrayPointerInt1[1] = &ib;
    arrayPointerInt1[2] = &ic;
    // 类型T 解析为int
    ShowArray(arrayInt1, 5);
    // 将类型T解析为int 更具体 假设数组的内容是指针 因此被使用
    ShowArray(arrayPointerInt1, 3);

    // 总之，重载解析将寻找最匹配的函数
    // 如果只存在一个匹配的函数 则使用它
    // 如果存在多个这样的函数 但是其中一个不是模版函数 则选择非模版函数
    // 如果都是模版函数 但是其中一个函数比其他函数更具体 则选择跟具体的函数
    // 如果存在多个同样合适的普通函数或模版函数 但咩有更具体 则产生多义性 则报错

    // 自己选择函数使用
    // 1. 定义一个模版函数
    // 2. 定义一个自定义实现
    // 3. 手动指定选择需要执行的函数
    int l1 = 10;
    int l2 = 20;
    double l3 = 1.1;
    double l4 = 1.3;
    my_add(l1, l2);  // int
    my_add<int>(l1, l2); // T
    my_add<int>(l3, l4);  // T
    my_add(l3, l4); // T

    // 函数模版的发展
    cout << "int add double: " << MyAdd(1, 3.1) << endl;
    cout << "double add double: " << MyAdd(1.1, 3.2) << endl;
    cout << "int  add char: " << MyAdd(1, 'a') << endl;
    // decltype的声明格式:
    // decltype (expression) var;
    // decltype的核对表过程简化:

    // 1. 第一步 如果expression是一个没有用括号括起的标识符, 那么var类型与该标识符号的类型相同 包括 const限定符号
    double xx1 = 1.1;
    decltype(xx1) xxx1;
    cout << "xxx1 type is: " << typeid(xxx1).name() << endl; // double

    const int xx2 = 1;
    decltype(xx2) xxx2 = 1;
    cout << "xxx2 type is: " << typeid(xxx2).name() << endl; //  int

    double& xx3 = xx1;
    decltype(xx3) xxx3 = xx1;
    cout << "xxx3 type is: " << typeid(xxx3).name() << endl; //  double&

    // 2. 第二步 如果expression是一个函数调用 则var的类型和函数返回类型相同。 注意 并不会真正的调用函数
    // 而是编译器通过检查函数的原型获取返回值类型
    decltype(my_add(1, 3)) xxx4;
    cout << "xxx4 type is: " << typeid(xxx4).name() << endl; //  int

    // 3. 第三步 如果expression是一个左值,则var为指向类型的引用(指向类型是啥 var就是啥类型)，这一部都是没有经过
    // (expression)的过程，但是在第一步就处理了，所以走到这一步，必须给左值使用括号,如果expression使用了括号括起来标识符号 则变成该类型的引用
    int xx5;
    decltype((xx5)) xxx5 = xx5; // int &
    decltype(xx5) xxx6; // int
    // 注意：括号是不会改变表达式的值和左值性
    int xx6 = 11;
    (xx6) = 19;
    // 不会影响 xx6

    // 4. 最后一步 如果条件都不满足 则var类型与expression的类型相同
    // 最后补充一下左值与右值概念
    // 左值:
    //      左值是可以标识位置的表达式，具有内存地址的表达式
    //      通常是可以被引用 可寻址的表达式 可以进行赋值
    //      包括变量 数组 指针 引用等表达式
    //      如: int a; a就是左值  int& x; x就是左值
    // 右值:
    //      不具备内存地址的表达式 无法被寻址的临时变量
    //      一般是临时生成 无法被寻址的变量或表达式
    //      包括常量 字面量 临时对象 表达式的计算结果
    //      如: x+5、10 、11+12
    // 总之: 左值是可以寻址的 可对其进行取址操作 右值是零时对象 不能进行寻址


}