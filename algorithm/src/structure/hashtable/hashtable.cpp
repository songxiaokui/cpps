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
        buckets = vector<Pair *>(BucketsNumber);
    }

    // 析构函数
    HashMap::~HashMap() {
        for (const auto &bucket: buckets) {
            if (bucket != nullptr) {
                cout << "释放元素： " << bucket->key << " value: " << bucket->value << endl;
                delete bucket;
            }
        }
        this->buckets.clear();
    }

    // 新增元素
    void HashMap::put(int key, string val) {
        int i_key = this->hash_func(key);
        Pair *pair = new Pair(i_key, val);
        this->buckets[i_key] = pair;
        cout << "key: " << key << " value: " << val << " 存储成功" << endl;
    }

    // 删除元素
    void HashMap::remove(int key) {
        int i_key = this->hash_func(key);
        if (this->buckets[i_key] != nullptr) {
            delete this->buckets[i_key];
            this->buckets[i_key] = nullptr;
            cout << "key: " << key << " 已删除" << endl;
        }
    }

    // 查询元素
    string HashMap::get(int key) {
        int i_key = this->hash_func(key);
        Pair *value = this->buckets[i_key];
        if (value == nullptr) {
            return "";
        }
        return value->value;
    }

    // 获取所有的键值对
    vector<Pair *> HashMap::pair_sets() {
        vector<Pair *> pair_set;
        for (Pair *bucket: this->buckets) {
            if (bucket != nullptr) {
                pair_set.push_back(bucket);
            }
        }
        return pair_set;
    }

    // 获取所有的键
    vector<int> HashMap::all_keys() {
        auto pair_set = this->pair_sets();
        vector<int> k_list;
        for (Pair *bucket: pair_set) {
            k_list.push_back(bucket->key);
        }
        return k_list;
    }

    // 获取所有的值
    vector<string> HashMap::all_values() {
        auto pair_set = this->pair_sets();
        vector<string> v_list;
        for (Pair *bucket: pair_set) {
            v_list.push_back(bucket->value);
        }
        return v_list;
    }

    // hash函数
    int HashMap::hash_func(int key) {
        return key % BucketsNumber;
    }

    // 打印hash表所有元素
    void HashMap::print() {
        cout << "hashmap 所有元素如下: " << endl;
        for (Pair *p: this->pair_sets()) {
            cout << "  key: " << p->key << " value: " << p->value << endl;
        }
    }

    void testHashTable(void) {
        cout << "hash table ..." << endl;
        HashMap hp;
        hp.put(101, "宋晓奎");
        hp.put(111, "宋晓奎");
        hp.put(123, "宋晓奎");
        hp.put(199, "宋晓奎");

        hp.remove(199);

        hp.print();
    }
}