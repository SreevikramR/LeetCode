#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		std::vector<ListNode*> stack;
		ListNode* curr = head;
		while (curr) {
			stack.push_back(curr);
			curr = curr->next;
		}
		if (stack.empty()) return nullptr;
		ListNode* newHead = stack.back();
		curr = stack.back();
		stack.pop_back();
		while(!stack.empty()) {
			curr->next = stack.back();
			curr = curr->next;
			stack.pop_back();
		}
		curr->next = nullptr;
		return newHead;
	}
};
