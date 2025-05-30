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
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head = nullptr;

        if (list1 && list2) {
            if (list1->val <= list2->val) {
                head = list1;
                list1 = list1->next;
            } else {
                head = list2;
                list2 = list2->next;
            }
        } else {
            return nullptr;
        }
        
        ListNode* curr = head;
        while (list1 || list2 ) {
            if (list1 && list2) {
                if (list1->val <= list2->val) {
                    curr->next = list1;
                    list1 = list1->next;
                } else {
                    curr->next = list2;
                    list2 = list2->next;
                }
            } else if (list1) {
                curr->next = list1;
                list1 = list1->next;
            } else if (list2) {
                curr->next = list2;
                list2 = list2->next;
            } else {
                return nullptr;
            }
            curr = curr->next;
        }
        return head;

    }
};
