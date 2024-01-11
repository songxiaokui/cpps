//
// Created by 宋晓奎 on 2024/1/11.
//

#include "hashtableplus.h"

namespace NewHashMap {

    Bucket::Bucket(int key, string value) {
        this->key = key;
        this->value = value;
    }

    void Pair::put(int key, string value) {
        if (this->buckets_link.empty()) {
            this->buckets_link = vector<shared_ptr<Bucket>>(0);
        }
        shared_ptr<Bucket> bucket = make_shared<Bucket>(key, value);
        this->buckets_link.push_back(bucket);
    }

    void Pair::remove(int key) {
        for (int index = 0; index < this->buckets_link.size(); index++) {
            shared_ptr<Bucket> bt = this->buckets_link[index];
            if (bt->key == key) {
                bt.reset();
                this->buckets_link[index] = nullptr;
            }
        }
    }

    Pair::Pair() {
        this->buckets_link = vector<shared_ptr<Bucket>>(0);
    }

    Pair::~Pair() {
        for (shared_ptr<Bucket> &p: this->buckets_link) {
            if (p != nullptr) {
                p.reset();
                p = nullptr;
            }
        }
        this->buckets_link.clear();
    }

    // hash表
    NewHashMap::NewHashMap() {
        this->buckets_link = vector<shared_ptr<Pair>>(BUCKET_NUMBER);
    }

    NewHashMap::~NewHashMap() {
        for (shared_ptr<Pair> &p: this->buckets_link) {
            if (p != nullptr) {
                p.reset();
            }
        }
        this->buckets_link.clear();
    }

    // hash函数
    int NewHashMap::hash_func(int key) {
        return key % BUCKET_NUMBER;
    }

    // 新增元素
    void NewHashMap::put(int key, string value) {
        int index = hash_func(key);
        if (this->buckets_link[index] == nullptr) {
            this->buckets_link[index] = make_shared<Pair>();
        }

        shared_ptr<Pair> subLink = this->buckets_link[index];
        subLink->put(key, value);
        cout << "数据: key=" << key << " value=" << value << "存储成功!" << endl;
        cout << "当前桶序号: " << index << " 元素个数: " << this->buckets_link[index]->buckets_link.size() << endl;
    }

    // 删除元素
    void NewHashMap::remove(int key) {
        int index = hash_func(key);
        shared_ptr<Pair> subLink = this->buckets_link[index];
        subLink->remove(key);
    }

    // 查询元素
    string NewHashMap::get(int key) {
        int index = hash_func(key);
        shared_ptr<Pair> subLink = this->buckets_link[index];
        for (int i = 0; i < subLink->buckets_link.size(); i++) {
            if (key == subLink->buckets_link[i]->key) {
                return subLink->buckets_link[i]->value;
            }
        }
        return "";
    }

    // 获取所有的键值对
    vector<shared_ptr<Bucket>> NewHashMap::pair_sets() {
        vector<shared_ptr<Bucket>> pair_set;
        for (shared_ptr<Pair> &p: this->buckets_link) {
            if (p == nullptr) {
                continue;
            }
            for (shared_ptr<Bucket> &f: p->buckets_link) {
                if (f != nullptr) {
                    pair_set.push_back(f);
                }
            }
        }
        return pair_set;
    }

    // 获取所有的键
    vector<int> NewHashMap::all_keys() {
        vector<int> all_key;
        for (int index = 0; index < this->buckets_link.size(); index++) {
            shared_ptr<Pair> p = this->buckets_link[index];
            if (p != nullptr) {
                all_key.push_back(index);
            }
        }
        return all_key;

    }

    // 获取所有的值
    vector<string> NewHashMap::all_values() {
        vector<string> result;
        for (auto &p: this->pair_sets()) {
            result.push_back(p->value);
        }
        return result;
    }

    // 打印hash表所有元素
    void NewHashMap::print() {
        for (auto &p: this->pair_sets()) {
            cout << "key: " << p->key << " value: " << p->value << endl;
        }
    }

    void testNewHashMap(void) {
        NewHashMap hp;
        hp.put(1, "宋晓奎");
        hp.put(101, "张三");

        hp.put(19, "李斯");
        hp.put(119, "胡海");

        hp.remove(19);

        cout << hp.get(1) << endl;
        cout << hp.get(101) << endl;

        hp.print();
    }

}