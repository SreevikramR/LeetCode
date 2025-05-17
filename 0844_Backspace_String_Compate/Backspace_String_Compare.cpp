using namespace std;
#include <string>
#include <stack>

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		stack<char> stackA;
		stack<char> stackB;
		for (char c: s) {
			if (c == '#') {
				if (stackA.size() != 0) stackA.pop();
			}
			else stackA.push(c);
		}
		for (char c: t) {
			if (c == '#') {
				if (stackB.size() != 0) stackB.pop();
			}
			else stackB.push(c);
		}
		if (stackA.size() != stackB.size()) return false;
		while (!stackA.empty() && !stackB.empty()) {
			if (stackA.top() != stackB.top()) return false;
			stackA.pop();
			stackB.pop();
		}
		return true;
	}
};
