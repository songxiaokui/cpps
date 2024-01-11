#include <iostream>
#include "src/structure/hashtable/hashtable.h"
#include "src/structure/hashtable/hashtableplus.h"
#include "src/structure/tree/tree.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    // hash表
    // cout << "存在hash冲突的hash表: " << endl;
    // HashTable::testHashTable();

    // 解决hash冲突的hash表
    // cout << "解决hash冲突的hash表: " << endl;
    // NewHashMap::testNewHashMap();

    // tree
    Tree::testTree();

    return 0;
}
