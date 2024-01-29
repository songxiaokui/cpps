//
// Created by 宋晓奎 on 2024/1/18.
//

#ifndef FILE_PRIORITY_QUEUE_H
#define FILE_PRIORITY_QUEUE_H

#endif //FILE_PRIORITY_QUEUE_H

#include <queue>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person {
    string name;
    int age;
    Person(string name, int age): name(name),age(age){};
};

template<class T>
struct MyCompare {
    bool operator()(const T& a, const T& b) {
        return a.age < b.age;
    }
};

// 优先队列
void testPriorityQueue();