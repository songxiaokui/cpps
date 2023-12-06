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

    for (const auto& hobby: xMing.Hobby) {
        cout << hobby << endl;
    };

    for (const auto& brother: xMing.Brother) {
        cout << brother << endl;
    };
};