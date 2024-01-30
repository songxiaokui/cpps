//
// Created by 宋晓奎 on 2024/1/26.
//
#include <stack>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 32. 最长有效括号
    int longestValidParentheses(string s) {
        // 定义一个比较的方法
        // 如果连续匹配上 则+2
        // 否则 使用 max 取最大值
        // 直到字符串遍历结束
        int result = 0;
        int length = s.size();
        if (!length) {
            return result;
        }

        // 存储下标 计算最大长度
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < length; i++) {
            // 如果是左括号 则压入栈中
            if (s[i] == '(') {
                // 记录初始位置
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    result = max(result, i - stk.top());
                }
            }
        }
        return result;
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};