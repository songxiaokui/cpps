//
// Created by 宋晓奎 on 2024/1/30.
//
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    /*
    * 102. 二叉树的层序遍历
     * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）
     * 输入：root = [3,9,20,null,null,15,7]
     * 输出：[[3],[9,20],[15,7]]
     * */
    vector <vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        vector<TreeNode*> st1;
        st1.push_back(root);
        while (!st1.empty())
        {
            vector<TreeNode*> st2;
            vector<int> data;
            // 只要st1不为空 贼将该队列头部元素弹出 并把值押入结果数组中 同时将该层的节点都加入到下层队列中 最后将队列替换为下层队列
            while (!st1.empty())
            {
                // 获取头部元素
                TreeNode* node = st1.front();
                // 删除头部元素
                st1.erase(st1.begin());
                if (node)
                {
                    data.push_back(node->val);
                    // 处理该节点的左右子节点
                    if (node->left) st2.push_back(node->left);
                    if (node->right) st2.push_back(node->right);
                }
            }

            // 处理结束 替换下层处理数据
            if (!data.empty())
            {
                result.push_back(data);
            }
            // 处理下层数据
            st1 = st2;
        }

        return result;
    }
};