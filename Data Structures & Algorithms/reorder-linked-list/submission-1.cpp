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
    void reorderList(ListNode* head) {
        ListNode* curr = head, *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = slow->next;
        ListNode* list2p = nullptr;
        slow->next = nullptr;
        while (list2 != nullptr) {
            ListNode* list2n = list2->next;
            list2->next = list2p;
            list2p = list2;
            list2 = list2n;
        }
        ListNode* first = head;
        ListNode* second = list2p;
        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};
