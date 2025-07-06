using namespace std;
#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		set<vector<int>> set;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			int start = i + 1;
			int end = nums.size() - 1;
			while (start < end) {
				if (nums[i] + nums[start] + nums[end] == 0) {
					vector<int> newVec{nums[i], nums[start], nums[end]};
					if (set.count(newVec) == 0) {
						set.insert(newVec);
						res.push_back(newVec);
						start++;
					}
				}
				if (nums[i] + nums[start] + nums[end] > 0) end--;
				else start++;
			}
		}
		return res;
	}
};
