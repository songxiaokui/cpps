//
// Created by 宋晓奎 on 2024/1/18.
//

#include "mylist.h"

void testListScan()
{
    vector<int> li{1, 2, 3, 4, 5};
    // 迭代器
    for (auto iter = li.begin(); iter != li.end(); iter++)
    {
        cout << "elem: " << *iter << " -> ";
    }
    cout << endl;

    // 范围遍历
    for (auto elem: li)
    {
        cout << "elem: " << elem << " -> ";
    }
    cout << endl;

    // 循环遍历
    int length = li.size();
    for (int i = 0; i < length; i++)
    {
        cout << "elem: " << li[i] << " -> ";
    }
    cout << endl;

    // 逆序遍历
    for (auto riter = li.rbegin(); riter != li.rend(); riter++)
    {
        cout << "elem: " << *riter << " -> ";
    }
    cout << endl;
}