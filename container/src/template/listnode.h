//
// Created by 宋晓奎 on 2024/1/24.
//

#ifndef CONTAINER_LISTNODE_H
#define CONTAINER_LISTNODE_H

#endif //CONTAINER_LISTNODE_H

#include <iostream>
#include <string>
#include <vector>

namespace LinkList {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}

        ~ListNode() {
            if (this->next != nullptr) {
                delete this->next;
                this->next == nullptr;
            }
        }
    };
    ListNode* removeNthFromEnd(ListNode* head, int n);
}