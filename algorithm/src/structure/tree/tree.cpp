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

    // DFS 深度优先遍历
    void DFS(Tree *&root) {
        if (!root) {
            return;
        }

        stack<Tree *> stk;
        stk.push(root);

        while (!stk.empty()) {
            // 获取栈顶元素并处理元素
            Tree *p = stk.top();
            // 删除第一个元素
            stk.pop();
            cout << p->val << "->";
            // 处理右节点,先入栈,后处理
            if (p->right) {
                stk.push(p->right);
            }

            // 处理左节点,后入栈,先处理
            if (p->left) {
                stk.push(p->left);
            }
        }
        cout << "NULL" << endl;
    }

    // 先序遍历
    void preorder_traversal(Tree* &root)
    {
        if (!root)
        {
            return;
        }
        cout << root->val << "->";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }

    // 中序遍历
    void inorder_traversal(Tree* &root)
    {
        if (!root)
        {
            return;
        }
        inorder_traversal(root->left);
        cout << root->val << "->";
        inorder_traversal(root->right);
    }

    // 后序遍历
    void postorder_traversal(Tree* &root)
    {
        if (!root)
        {
            return;
        }
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->val << "->";
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
        cout << "BFS层序遍历: " << endl;
        BFS(root);

        cout << "DFS非递归 先序遍历: " << endl;
        DFS(root);

        cout << "先序遍历: " << endl;
        preorder_traversal(root);
        cout << "NULL" << endl;

        cout << "中序遍历: " << endl;
        inorder_traversal(root);
        cout << "NULL" << endl;

        cout << "后序遍历: " << endl;
        postorder_traversal(root);
        cout << "NULL" << endl;
        // 释放空间
        delete root;
    }
}