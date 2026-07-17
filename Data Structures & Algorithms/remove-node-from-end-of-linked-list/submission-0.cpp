/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* c = head, *p = nullptr;
        if (head->next == nullptr) return nullptr;
        int size = 0;
        while (c != nullptr) {
            c = c->next;
            size++;
        }
        c = head;
        int k = size - n;
        if (k <= 0) {
            ListNode* newHead = head->next;
            head->next = nullptr;
            return newHead;
        }
        for (int i = 0; i < k; ++i) {
            p = c;
            c = c->next;
        }
        p->next = c->next;
        c->next = nullptr;
        return head;
    }
};
