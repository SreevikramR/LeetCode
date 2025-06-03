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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode* curr = head;
        while (curr) {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        if (vec.size() == 1) return true;

        int i = 0;
        int size = vec.size();
        int half = (vec.size() / 2) + 1;
        while (i < vec.size() || i < half) {
            if (vec[i] != vec[size - 1 - i]) return false;
            i++;
        }
        return true;
    }
};
