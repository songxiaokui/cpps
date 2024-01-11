//
// Created by 宋晓奎 on 2024/1/11.
//

#include "tree.h"

namespace Tree {
    Tree::Tree(int val) : val(val), left(nullptr), right(nullptr) {}

    // 析构
    Tree::~Tree() {
        if (this->left) {
            delete this->left;
            this->left = nullptr;

        }
        if (this->right) {
            delete this->right;
            this->right = nullptr;
        }
    }

    // BFS 广度优先遍历
    void BFS(Tree *&root) {
        vector<Tree *> queue;
        queue.push_back(root);
        // 初始化动态数组
        // 将根节点放在数组中
        while (!queue.empty()) {
            // 弹出当前元素
            Tree *current_node = queue.front();
            // 删除当前元素(头部)
            queue.erase(queue.begin());

            // 输出数据
            cout << current_node->val << "->";
            // 如果左子节点不为空 加入数组
            if (current_node->left != nullptr) {
                queue.push_back(current_node->left);
            }
            // 如果右子节点不为空 加入数组
            if (current_node->right != nullptr) {
                queue.push_back(current_node->right);
            }
        }

        cout << "NULL" << endl;
        queue.clear();
    }

    void testTree(void) {
        // 节点初始化
        Tree *root = new Tree(0);
        Tree *p1 = new Tree(1);
        Tree *p2 = new Tree(2);
        Tree *p3 = new Tree(3);
        Tree *p4 = new Tree(4);
        Tree *p5 = new Tree(5);
        Tree *p6 = new Tree(6);
        root->left = p1;
        root->right = p2;
        p1->left = p3;
        p1->right = p4;
        p2->left = p5;
        p2->right = p6;

        // BFS遍历树
        BFS(root);
        // 释放空间
        delete root;
    }
}