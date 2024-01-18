//
// Created by 宋晓奎 on 2024/1/18.
//

#include "queue.h"

template<typename T>
void print(queue<T> &q) {
    while (!q.empty()) {
        cout << q.front() << "->";
        q.pop();
    }
    cout << "End" << endl;
}

void testQueue() {
    // 队列的使用
    // FIFO
    // 创建队列
    queue<int> mq;

    // 压入元素
    mq.push(1);
    mq.push(2);
    mq.push(3);

    // 访问队列头部元素
    cout << mq.front() << endl;

    // 访问队列尾部元素
    cout << mq.back() << endl;

    // 删除首部元素
    mq.pop();

    // 获取队列的长度
    cout << mq.size() << endl;

    // 判断队列是否为空
    cout << mq.empty() << endl;

    cout << "交换前: " << endl;
    print(mq);

    // 队列交换
    queue<int> sq;
    sq.push(4);
    sq.push(5);
    sq.push(6);
    mq.swap(sq);
    cout << "交换后: " << endl;
    print(mq);

    // emplace 尾部构造函数
    queue<int> eq;
    eq.emplace(1);
    eq.emplace(2);
    eq.emplace(3);
    print(eq);

    // string
    queue<float> fq;
    fq.push(1.1);
    fq.push(2.1);
    fq.push(3.1);
    print(fq);
}