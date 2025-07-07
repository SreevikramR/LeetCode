#include <stack>
using namespace std;

class MinStack {
public:
	stack<int> min_stack;
	stack<int> order_stack;

	MinStack() {}

	void push(int val) {
		order_stack.push(val);
		if (min_stack.empty() || val <= min_stack.top()) min_stack.push(val);
	}

    void pop() {
		int val = order_stack.top();
		if (val == min_stack.top()) min_stack.pop();
		order_stack.pop();
    }

    int top() {
    	return order_stack.top();
    }

    int getMin() {
    	return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
