class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<pair<int, int>> stack;
		stack.push(pair<int,int>{temperatures[0], 0});
		vector<int> res(temperatures.size(), 0);
		for (int i = 1; i < temperatures.size(); i++) {
			while (!stack.empty()) {
				if (temperatures[i] > stack.top().first) {
					res[stack.top().second] = i - stack.top().second;
					stack.pop();
				} else {
					break;
				}
			}
            stack.push(pair<int, int>{temperatures[i], i});
		}
		return res;
	}
};
