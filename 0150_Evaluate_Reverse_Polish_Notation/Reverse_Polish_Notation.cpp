using namespace std;
#include <string>
#include <vector>
#include <stack>

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<string> stack;
		for (string s: tokens) {
			if (s == "+" || s == "-" || s == "*" || s == "/") {
				int second = stoi(stack.top());
				stack.pop();
				int first = stoi(stack.top());
				stack.pop();
				if (s == "+") stack.push(to_string(first + second));
				else if (s == "-") stack.push(to_string(first - second));
				else if (s == "*") stack.push(to_string(first * second));
				else if (s == "/") stack.push(to_string(first / second));
			} else {
				stack.push(s);
			}
		}
		return stoi(stack.top());
	}
};
