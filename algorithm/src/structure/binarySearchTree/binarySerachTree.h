//
// Created by austsxk on 2024/1/13.
//

#ifndef ALGORITHM_BINARYSERACHTREE_H
#define ALGORITHM_BINARYSERACHTREE_H

#endif //ALGORITHM_BINARYSERACHTREE_H

// 实现二叉搜索树
/*
 * 二叉搜索树满足以下条件
 * 1. 对于根节点，左子树节点的值都小于根，右子树节点的值大于根的值
 * 2. 对于任何节点的左子树和右子树 都满足1的条件
 */

#include <iostream>
#include <string>
#include "../tree/tree.h"

using namespace std;


namespace BinarySearchTree {
    class BST {
    public:
        BST();
        ~BST();
        // 插入元素
        void Insert(int val);
        // 查询元素
        Tree::Tree* Search(int val);
        // 删除元素
        void Remove(int val);
        // 中序遍历元素
        void Print(void);
        void InorderTraversal(Tree::Tree*& root);

    private:
        Tree::Tree* root;
    };

    void testBinarySearchTree(void);
}