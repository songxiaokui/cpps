//
// Created by 宋晓奎 on 2024/1/11.
//

#ifndef ALGORITHM_HASHTABLEPLUS_H
#define ALGORITHM_HASHTABLEPLUS_H

#endif //ALGORITHM_HASHTABLEPLUS_H

// 使用链式法解决hash冲突重写hash表
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace NewHashMap
{
    const int BUCKET_NUMBER = 100;
    void testNewHashMap(void);

    // 存储键值对
    struct Bucket
    {
        int key;
        string value;
        Bucket(int key, string value);
    };

    // 存储key相同的键值对列表
    struct Pair
    {
        vector<shared_ptr<Bucket>> buckets_link;
        Pair();
        ~Pair();
        void put(int key, string value);
        void remove(int key);

    };

    class NewHashMap {
    private:
        vector<shared_ptr<Pair>> buckets_link;
    public:
        NewHashMap();
        ~NewHashMap();

        // hash函数
        int hash_func(int key);
        // 新增元素
        void put(int key, string value);
        // 删除元素
        void remove(int key);
        // 查询元素
        string get(int key);
        // 获取所有的键值对
        vector<shared_ptr<Bucket>> pair_sets();
        // 获取所有的键
        vector<int> all_keys();
        // 获取所有的值
        vector<string> all_values();
        // 打印hash表所有元素
        void print();
    };
}