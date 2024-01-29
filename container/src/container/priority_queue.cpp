//
// Created by 宋晓奎 on 2024/1/18.
//

#include "priority_queue.h"
void testPriorityQueue()
{
    // 优先队列
    // 大顶堆
    std::priority_queue<int> maxHeap;
    maxHeap.push(1);
    maxHeap.push(5);
    maxHeap.push(3);
    cout << maxHeap.top() << endl;
    maxHeap.pop();
    cout << maxHeap.top() << endl;

    // 小顶堆
    std::priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(9);
    minHeap.push(1);
    minHeap.push(2);
    cout << minHeap.top() << endl;
    minHeap.pop();
    cout << minHeap.top() << endl;

    // 自定义数据结构存储
    // 自定义lambda函数
    auto func = [](Person& a, Person& b) {return a.age < b.age;};
    // 使用类型推断可以 也可以定义一个对象 重载operator函数
    // std::priority_queue<Person, vector<Person>, decltype(func)> customQ(func);
    std::priority_queue<Person, vector<Person>, MyCompare<Person>> customQ;
    Person p1 = Person("sxk1", 18);
    Person p2 = Person("sxk2", 24);
    Person p3 = Person("sxk3", 19);
    Person p4 = Person("sxk4", 29);
    customQ.push(p1);
    customQ.push(p2);
    customQ.push(p3);
    customQ.push(p4);
    while (!customQ.empty())
    {
        auto p = customQ.top();
        cout << "name=" << p.name << " age=" << p.age << endl;
        customQ.pop();
    }

}