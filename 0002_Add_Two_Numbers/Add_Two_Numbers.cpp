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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr_l1 = l1;
        ListNode* curr_l2 = l2;
        ListNode* outputHead = nullptr;
        ListNode* curr = outputHead;

        int carry = 0;
        while(curr_l1 || curr_l2 || carry) {
            int sum = carry;
            if (curr_l1) {
                sum += curr_l1->val;
                curr_l1 = curr_l1->next;
            }

            if (curr_l2) {
                sum += curr_l2->val;
                curr_l2 = curr_l2->next;
            }

            carry = sum / 10;
            if (curr) {
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
            } else {
                outputHead = new ListNode(sum % 10);
                curr = outputHead;
            }
        }

        return outputHead;
    }
};
