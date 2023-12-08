//
// Created by 宋晓奎 on 2023/12/8.
//

#include "reference.h"

void increment(int& a);
void increment(int& a)
{
    a++;
}

int& increment2(int& f);
int& increment2(int& f)
{
    f *= 2;
    return f;
}

struct Fish
{
    string breed;
    float weight;
    float length;
};

enum Response
{
    No,
    Yes,
    Maybe,

};

struct CandyBar
{
    string breed;
    float wight;
    float kll;
};

void testReference(void)
{
    cout << "this is reference test..." << endl;

    int a(10);
    int& b = a;
    cout << "a = " << a << endl;
    cout << "a的引用b = "<< b << endl;
    cout << "a 的地址" << &a << endl;
    cout << "a的引用b的地址 = "<< &b << endl;

    int c(100);
    b = c;
    cout << "c的地址: " << &c << endl;
    cout << "a的值为: " << a << endl;
    cout << "b引用的值为: " << b << endl;
    cout << "b引用的值的地址为: " << &b << endl;
    // 说明引用初始化后 指向的地址不会在进行更新

    c= 101;
    cout << "a的值为: " << a << endl;
    cout << "b引用的值为: " << b << endl;
    // b在初始化后 地址不变了 虽然b赋值了c 但是c的改变不会影响a和b

    // 引用作为参数
    int d = 1;
    int& e = d;
    increment(e);
    increment(e);
    increment(e);
    cout << "d = " << d<< endl;

    // 通过引用传递函数返回值
    int f = 10;
    int& g = increment2(f);
    cout << "f = " << f << endl;
    cout << "g = " << g << endl;

    // array的定义与使用
    array<int, 5> ia1{};
    array<double, 2> fa1 = {.11, 1.1};

    cout << ia1.size() << endl;
    for (auto iter = ia1.begin(); iter < ia1.end(); iter++)
    {
        cout << *iter << endl;
    }

    // 练习题
    // 第四章
    // 1
    char actor[30]{};
    short betsie[100]{};
    float chuck[13]{};
    long double dipsea[64];
    // 2
    array<char, 30> actorArray{};
    array<short, 100> betsieArray{};
    array<float, 13> chuckArray{};
    array<long double, 64> dipseaArray{};
    // 3
    array<int, 5> array1 = {1, 3, 5, 7, 9};
    // 4
    int even = array1.at(0) + array1.at(4);
    cout << even << endl;
    // 5
    vector<float> ideas(5, 0);
    cout << ideas[1]  << endl;
    // 6
    char str[] = "cheese-burger";
    cout << str << endl;
    // 7
    string str2 = "waldorf Salad";
    cout << str2 << endl;
    // 8 9
    struct Fish f1 = {"马哈鱼", 2.1, 40};

    // 10
    cout << Maybe << endl;

    // 11
    double ted(100);
    double* pted = &ted;
    cout << *pted << endl;

    // 12
    float treacle[10] = {1,2,3,4,5,6,7,8,9,10};
    float* ptreacle = treacle;
    cout << "第一个元素: "<< *ptreacle << endl;
    cout << "第10个元素: " << *(ptreacle+9) << endl;

    // 13
    int l(10);
    // cin >> l;
    int* ar = new int [l];
    for (int i = 0; i < l;i++)
    {
        ar[i] = i*i;
        cout << ar[i] << endl;
    }

    cout << "vector"<<endl;
    vector<int> ar2(l, 100);
    for (int i = 0; i < l;i++)
    {
        ar2[i] = i*i;
        cout << ar2[i] << endl;
    }

    // 14
    // 输出的是首地址

    // 15
    struct Fish* pf = new Fish;
    pf = &f1;
    cout << "名字："<<pf->breed << endl;

    // 16
    // address 遇到第一个单词就终止 会存入到输入队列中 等待第二次输入

    // 17
    const int number = 10;
    vector<string> vs1(number, "");
    array<string, number> vs2;


    // 编程题
    //1
    // getLinePractice();

    //2略

    //3
    char n1[] = "Flip";
    char n2[] = "Fleming";
    char* n3 = new char [strlen(n1)+strlen(n2)+1];
    char*& n4 = n3;
    strcpy(n3, n1);
    n3 = n3+ strlen(n1);
    cout << "n3: "<< n3<<endl;
    strcpy(n3, n2);
    n3-=strlen(n1);
    cout << "n4: " << n4 << endl;

    //5
    struct CandyBar snack = {
            "Mocha Munch",
            2.3,
            350,
    };
    cout << "重力为: " << snack.wight << endl;

    //6
    struct CandyBar* car = new struct CandyBar [3];
    for (int i = 0; i < 3; i++){
        cout << car[i].wight << endl;
    }
}

void getLinePractice(void)
{
    // 主要练习的是cin cin.get(变量, 长度) get()丢掉空行 getline()
    string firstname{};
    cout << "What is your first name?";
    std::getline(cin, firstname);
    cout << firstname << endl;
    char* lastName = new char;
    cout << "What is your  name?";
    cin.get(lastName, 80).get();
    cout << lastName << endl;
}
