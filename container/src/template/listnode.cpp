//
// Created by 宋晓奎 on 2024/1/24.
//

#include "listnode.h"


namespace LinkList {
    using namespace std;
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 解题思路
        // 首先可以定义一个哑节点 方便处理头部元素
        ListNode *dummyNode = new ListNode(0, head);
        // 删除元素 通常要找删除该元素的前驱节点和后继节点 然后让前驱节点的 next 指向被删除节点的后继节点即可
        // 使用快慢指针用来找指定位置的元素
        // 如找倒数第 n 个
        // 可以先让快节点走 n步 然后慢节点和快节点同时走 直到走到尾部 就可以找到删除节点的前驱节点
        // head--> 1 --> 2 --> 3 --> 4 --> 5
        // 当前 fast 和 slow 在 head
        // 删除倒数 2 号元素 也就是 4
        // 快节点走 2 步 到达节点 2 号位置
        // 此时慢节点和快节点同时走 直到快节点到尾部
        // 也就是走 3步到尾部
        // 此时慢节点刚好走到删除元素 的前驱节点 3，fast 节点为 nullptr
        ListNode *fast = dummyNode;
        ListNode *slow = dummyNode;
        int i = 0;
        while (i < n + 1) {
            fast = fast->next;
            i++;
        }

        // 然后快慢指针同时走
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // 找到被删除的节点
        ListNode *deleteNode = slow->next;
        // 删除节点
        slow->next = deleteNode->next;
        // 释放删除的节点内存
        delete deleteNode;

        return dummyNode->next;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummyNode = new ListNode(0, nullptr);
        ListNode *result = dummyNode;

        while (list1 && list2) {
            // 比较值 确定指向
            if (list1->val <= list2->val) {
                dummyNode->next = list1;
                list1 = list1->next;
            } else {
                dummyNode->next = list2;
                list2 = list2->next;
            }
            dummyNode = dummyNode->next;
        }

        if (list1) {
            dummyNode->next = list1;
        }
        if (list2) {
            dummyNode->next = list2;
        }

        return result->next;
    };


    // 判断是否都为空
    bool getNull(vector<ListNode*>& lists)
    {
        bool status = false;
        for (auto iter = lists.begin(); iter != lists.end(); iter++)
        {
            if (*iter)
            {
                status = true;
            }
        }
        return status;
    }

    // 获取最大的元素
    int getMin(vector<ListNode*>& lists)
    {
        if (!lists.size())
        {
            return -1;
        }
        int index = -1;
        int value = 0;
        for (int i = 0; i<lists.size();i++)
        {
            if (!lists[i]) {
                continue;
            }

            if (index == -1)
            {
               index = i;
               value = lists[index]->val;
               continue;
            }

            if (lists[i]->val < value)
            {
               index = i;
               value = lists[i]->val;
            }
        }
        return index;
    }

    void Update(vector<ListNode*>& lists, int index)
    {
        if (index != -1)
        {
            lists[index] = lists[index]->next;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyNode = new ListNode(0, nullptr);
        ListNode* result = dummyNode;
        while (getNull(lists))
        {
            int index = getMin(lists);
            if (index != -1)
            {
                dummyNode->next = lists[index];
                Update(lists, index);
                dummyNode = dummyNode->next;
            }
        }
        return result->next;
    }

}

