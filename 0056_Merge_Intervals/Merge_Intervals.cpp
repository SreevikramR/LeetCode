using namespace std;
#include <algorithm>
#include <vector>

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[0] < b[0];
		});
		vector<vector<int>> new_ints;
		new_ints.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++) {
			if (new_ints.back()[1] + 1 > intervals[i][0]) new_ints.back()[1] = max(intervals[i][1], new_ints.back()[1]);
			else new_ints.push_back(intervals[i]);
		}
		return new_ints;
	}
};
