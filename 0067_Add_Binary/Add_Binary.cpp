using namespace std;
#include <stack>
#include <string>

class Solution {
public:
	string addBinary(string a, string b) {
		stack<char> stackA;
		stack<char> stackB;
		if (a.length() > b.length()) {
			for (int i = b.length(); a.length() > i; i++) stackB.push('0');
		}
		if (a.length() < b.length()) {
			for (int i = a.length(); i < b.length(); i++) stackA.push('0');
		}

		for (char c: a) {
			stackA.push(c);
		}
		for (char c: b) {
			stackB.push(c);
		}
		int carry = 0;
		string number = "";
		while (!stackA.empty() && !stackB.empty()) {
            int queueANum = stackA.top() - '0';
            int queueBNum = stackB.top() - '0';
			int total = queueANum + queueBNum + carry;
			if (total == 3) {
				carry = 1;
				number = "1" + number;
			} else if (total == 2) {
				carry = 1;
				number = "0" + number;
			} else if (total == 1) {
				carry = 0;
				number = "1" + number;
			} else {
				carry = 0;
				number = "0" + number;
			}
            stackA.pop();
            stackB.pop();
		}
        if (carry) number = "1" + number;
		return number;
	}
};
