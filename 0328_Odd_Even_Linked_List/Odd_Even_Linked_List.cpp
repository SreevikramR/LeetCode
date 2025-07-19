
using namespace std;
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		queue<ListNode*> odd;
		queue<ListNode*> even;
		int count = 1;
		ListNode* curr = head;
		while (curr) {
			if (count % 2 == 1) odd.push(curr);
			else even.push(curr);
			curr = curr->next;
			count++;
		}
		if (!head) return nullptr;
		curr = head;
		odd.pop();

		while (!odd.empty()) {
			curr->next = odd.front();
			odd.pop();
			curr = curr->next;
		}

		while (!even.empty()) {
			curr->next = even.front();
			even.pop();
			curr = curr->next;
		}

		curr->next = nullptr;
		return head;
	}
};
