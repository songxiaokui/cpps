//
// Created by 宋晓奎 on 2024/1/12.
//

#include "listtree.h"

namespace ListTree {
    // 构造函数
    Tree::Tree(vector<int> &li) {
        this->data_list = li;
    }

    Tree::~Tree() {
        this->data_list.clear();
    }

    // 获取当前索引所在的值
    int Tree::val(int index) {
        if (index >= this->get_length() || index < 0) {
            return INT_MAX;
        }
        return this->data_list[index];
    }

    // 根据当前索引获取左子节点所在索引
    int Tree::get_left(int index) {
        return 2 * index + 1;
    }

    // 根据当前索引获取右子节点
    int Tree::get_right(int index) {
        return 2 * index + 2;
    }

    // 根据当前节点获取父亲节点
    int Tree::parent(int index) {
        return (index - 1) / 2;
    }

    // 获取当前数组长度
    int Tree::get_length() {
        return this->data_list.size();
    }

    // 层序遍历
    void Tree::bfs() {
        for (auto iter = this->data_list.begin(); iter != this->data_list.end(); iter++) {
            cout << (*iter) << "->";
        }
        cout << "NULL" << endl;
    }

    // 先序遍历
    void Tree::preorder_traversal() {
        this->dfs(0, "pre");
    }

    // 中序遍历
    void Tree::inorder_traversal() {
        this->dfs(0, "in");
    }

    // 后序遍历
    void Tree::postorder_traversal() {
        this->dfs(0, "post");
    }

    // dfs递归实现
    void Tree::dfs(int index, string tp) {
        // 判断是否为空
        if (this->val(index) == INT_MAX) {
            return;
        }

        // 先序遍历
        if (tp == "pre") {
            cout << this->val(index) << "->";
        }

        // 左子树
        this->dfs(this->get_left(index), tp);

        // 中序遍历
        if (tp == "in") {
            cout << this->val(index) << "->";
        }

        // 右子树
        this->dfs(this->get_right(index), tp);

        // 后序遍历
        if (tp == "post") {
            cout << this->val(index) << "->";
        }
    }


    void testListTree(void) {
        vector<int> lt = vector<int>{1, 2, 3, 4, 5, 6, 7, 8};
        Tree p(lt);
        cout << "层序遍历: " << endl;
        p.bfs();

        cout << "先序遍历: " << endl;
        p.preorder_traversal();
        cout << "NULL" << endl;

        cout << "中序遍历: " << endl;
        p.inorder_traversal();
        cout << "NULL" << endl;

        cout << "后序遍历: " << endl;
        p.postorder_traversal();
        cout << "NULL" << endl;
    }
}