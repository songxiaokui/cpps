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
}