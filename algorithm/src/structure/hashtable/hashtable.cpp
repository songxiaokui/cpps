//
// Created by 宋晓奎 on 2024/1/10.
//

#include "hashtable.h"

namespace HashTable {
    Pair::Pair(int key, string value) {
        this->key = key;
        this->value = value;
    }


    // 构造函数
    HashMap::HashMap() {
        this->buckets = vector<Pair*>(BucketsNumber);
    }

    // 析构函数
    HashMap::~HashMap() {
        for (Pair* const& bucket: this->buckets)
        {
            delete bucket;
        }
        this->buckets.clear();
    }

    // 新增元素
    void HashMap::put(int key, string val) {
        int i_key = this->hash_func(key);
        Pair* pair = new Pair(i_key, val);
        this->buckets[i_key] = pair;
    }

    // 删除元素
    void HashMap::remove(int key) {

    }

    // 查询元素
    string HashMap::get(int key) {

    }

    // 获取所有的键值对
    vector<Pair *> HashMap::pair_sets() {

    }

    // 获取所有的键
    vector<int> HashMap::all_keys() {

    }

    // 获取所有的值
    vector<string> HashMap::all_values() {

    }

    // hash函数
    int HashMap::hash_func(int key) {
        return key % BucketsNumber;
    }

    // 打印hash表所有元素
    void HashMap::print() {

    }

}