//
// Created by austsxk on 2024/1/13.
//

#include "binarySerachTree.h"

namespace BinarySearchTree {
    // 构造
    BST::BST() {
        this->root = nullptr;
    }

    // 析构
    BST::~BST() {
        if (this->root != nullptr) {
            delete this->root;
            this->root = nullptr;
        }
    }

    // 插入元素
    void BST::Insert(int val) {
        // 若节点为空 创建根节点
        if (!this->root) {
            this->root = new Tree::Tree(val);
            return;
        }
        // 查询到需要插入节点的父节点
        Tree::Tree *prvNode = nullptr;
        Tree::Tree *current = this->root;
        while (current) {
            if (current->val == val) {
                cout << "插入的节点: " << val << " 已存在" << endl;
                return;
            }
            prvNode = current;
            // 如果value 大于当前节点的值 则插入右侧 反之插入左侧
            if (val > current->val) {
                current = current->right;
            } else {
                current = current->left;
            }
        }

        // 此时需要插入节点
        if (val > prvNode->val) {
            prvNode->right = new Tree::Tree(val);
        } else {
            prvNode->left = new Tree::Tree(val);
        }
        cout << "节点：" << val << "插入成功！" << endl;
    }

    // 查询元素
    Tree::Tree *BST::Search(int val) {
        if (this->root == nullptr) {
            return nullptr;
        }
        Tree::Tree *currentNode = this->root;
        while (currentNode) {
            if (currentNode->val == val) {
                break;
            }
            if (val > currentNode->val) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }

        }
        if (currentNode) {
            return currentNode;
        }
        return nullptr;
    }

    // 删除元素
    void BST::Remove(int val) {
        // 删除元素区分3种情况
        // 0和1 2个度
        // 1. 先找到需要删除的节点
        if (!this->root) {
            return;
        }
        // 查询到需要插入节点的父节点
        Tree::Tree *prvNode = nullptr;
        Tree::Tree *current = this->root;
        while (current) {
            if (current->val == val) {
                break;
            }
            prvNode = current;
            // 如果value 大于当前节点的值 则插入右侧 反之插入左侧
            if (val > current->val) {
                current = current->right;
            } else {
                current = current->left;
            }
        }

        // 无元素
        if (!current) {
            cout << "未找到到需要删除的元素: " << val << endl;
            return;
        }

        // 如果删除的元素为叶子节点 或者删除的元素只有一个子节点
        if (current->left == nullptr || current->right == nullptr) {
            Tree::Tree *child = nullptr;
            if (current->right) {
                // 左节点存在
                child = current->right;
            } else {
                // 右节点存在 或者 都不存在 当前节点为叶子节点
                child = current->left;
            }

            // 判断是否为根
            if (current != this->root) {
                if (current == prvNode->left) {
                    // 若删除的节点为父亲节点的左节点
                    prvNode->left = child;
                } else {
                    prvNode->right = child;
                }
            } else {
                // 如果当前处理的节点为根
                this->root = child;
            }
        } else {
            // 删除的节点有左、右子树
            // 先获取到当前删除节点 中序遍历的后继节点 然后使该节点变为当前删除的节点
            Tree::Tree *temp = current->right;
            while (temp->left) {
                temp = temp->left;
            }
            // 此时以及找到当前删除节点的后继节点
            // 删除该节点
            this->Remove(temp->val);
            // 同时 将删除节点的值 替换为后继节点的值 从而完成树的调整
            current->val = temp->val;
        }

    }

    // 输出元素
    void BST::Print(void) {
        this->InorderTraversal(this->root);
    }

    // 中序号遍历
    void BST::InorderTraversal(Tree::Tree *&root) {
        if (!root) {
            return;
        }
        // 左
        this->InorderTraversal(root->left);
        // 中
        cout << root->val << "->";
        // 右
        this->InorderTraversal(root->right);
    }

    // 测试二叉搜索树
    void testBinarySearchTree(void)
    {
        cout << "二叉搜索树测试: " << endl;
        class BST bst = BST();
        bst.Insert(10);
        bst.Insert(5);
        bst.Insert(3);
        bst.Insert(7);
        bst.Insert(15);
        bst.Insert(12);
        bst.Insert(18);

        cout << "打印二叉搜索树: " << endl;
        bst.Print();
        cout << endl;

        // 查询元素
        auto node = bst.Search(5);
        if (node)
        {
            cout << "元素5搜索到!" << endl;
        }

        auto node1 = bst.Search(99999);
        if (node1)
        {
            cout << "元素99999搜索到!" << endl;
        } else {
            cout << "元素99999未搜索到!" << endl;
        }

        // 删除叶子节点
        bst.Remove(3);
        cout << "删除3后的输出: " << endl;
        bst.Print();
        cout << endl;

        // 插入3 6
        bst.Insert(3);
        bst.Insert(6);
        cout << "删除元素7后: " << endl;
        bst.Remove(7);
        bst.Print();
        cout << endl;

        // 插入7 搜索2个节点的5
        cout << "删除元素5，度为2的节点: " << endl;
        bst.Insert(7);
        bst.Remove(5);
        bst.Print();
        cout << endl;
    }
}