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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> numbers;
        ListNode* curr = head;
        while(curr) {
            numbers.push_back(curr);
            curr = curr->next;
        }
        return numbers[numbers.size() / 2];
    }
};
