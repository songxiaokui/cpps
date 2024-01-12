//
// Created by 宋晓奎 on 2024/1/12.
//

#ifndef ALGORITHM_LISTTREE_H
#define ALGORITHM_LISTTREE_H

#endif //ALGORITHM_LISTTREE_H

// 使用列表实现二叉树的存储
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace ListTree {
    // 定义一个使用列表存储数据表示树的结构
    // 实现树的层、先、中、后遍历
    class Tree {
    private:
        vector<int> data_list;
    public:
        Tree(vector<int>& li);

        ~Tree();

        // 获取当前索引所在的值
        int val(int index);

        // 根据当前索引获取左子节点所在索引
        int get_left(int index);

        // 根据当前索引获取右子节点
        int get_right(int index);

        // 根据当前节点获取父亲节点
        int parent(int index);

        // 获取当前数组长度
        int get_length();

        // 层序遍历
        void bfs();

        // 先序遍历
        void preorder_traversal();

        // 中序遍历
        void inorder_traversal();

        // 后序遍历
        void postorder_traversal();

        // dfs递归实现
        void dfs(int index, string tp);
    };

    void testListTree(void);
}
