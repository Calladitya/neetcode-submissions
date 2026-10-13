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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* current1 = list1;
        ListNode* current2 = list2;
        ListNode* current3 = nullptr;
        ListNode* head = nullptr;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->val < current2->val) {
                if (head == nullptr) {
                    head = current1;
                    current3 = current1;
                } else {
                    current3->next = current1;
                    current3 = current1;
                }
                current1 = current1->next;
            } else {
                if (head == nullptr) {
                    head = current2;
                    current3 = current2;
                } else {
                    current3->next = current2;
                    current3 = current2;
                }
                current2 = current2->next;
            }
        }

        if (current1 != nullptr) {
            current3->next = current1;
        }

        if (current2 != nullptr) {
            current3->next = current2;
        }

        return head;
    }
};