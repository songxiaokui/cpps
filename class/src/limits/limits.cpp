//
// Created by 宋晓奎 on 2023/12/11.
//

#include "limits.h"

class Person {
    // 公共权限
public:
    string name;

    void update() {
        this->name = "张三";
        this->m_car = "宝马";
        this->password = "123456";
    }

    // 保护权限
protected:
    string m_car;
    // 私有权限
private:
    string password;
};

void testLimits() {
    Person p;
    p.name = "张三";
    // p.m_car = "奔驰";  // 不可以访问
}