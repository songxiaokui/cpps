//
// Created by 宋晓奎 on 2024/1/10.
//

#ifndef ALGORITHM_HASHTABLE_H
#define ALGORITHM_HASHTABLE_H

#endif //ALGORITHM_HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace HashTable {
    const int BucketsNumber = 100;
    // hash表存储的键值对
    struct Pair {
    public:
        int key;
        string value;

        Pair(int key, string value);
    };

    // 定义一个hashMap
    class HashMap {
        // 存储桶数据
    private:
        vector<Pair *> buckets;

    public:
        // 构造函数
        HashMap();
        // 析构函数
        ~HashMap();
        // 新增元素
        void put(int key, string value);
        // 删除元素
        void remove(int key);
        // 查询元素
        string get(int key);
        // 获取所有的键值对
        vector<Pair*> pair_sets();
        // 获取所有的键
        vector<int> all_keys();
        // 获取所有的值
        vector<string> all_values();
        // hash函数
        int hash_func(int key);
        // 打印hash表所有元素
        void print();
    };
}