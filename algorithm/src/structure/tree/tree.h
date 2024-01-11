//
// Created by 宋晓奎 on 2024/1/11.
//

#ifndef ALGORITHM_TREE_H
#define ALGORITHM_TREE_H

#endif //ALGORITHM_TREE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Tree {
    struct Tree {
        int val;
        Tree *left;
        Tree *right;

        Tree(int val);
        ~Tree();
    };

    void testTree(void);

    // BFS 广度优先遍历
    void BFS(Tree* &root);
}