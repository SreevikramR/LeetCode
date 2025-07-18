#include <cmath>
using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	int getDecimalValue(ListNode* head) {
		int val = 0;
		while (head) {
			val = val * 2 + head->val;
			head = head->next;
		}
		return val;
	}
};
