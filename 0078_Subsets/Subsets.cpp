using namespace std;
#include <vector>

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> subarray;
		backtrack(result, subarray, nums, 0);
		return result;
	}

	void backtrack(vector<vector<int>> &result, vector<int> &subArray, vector<int> &nums, int start) {
		result.push_back(subArray);
		for (int i = start; i < nums.size(); i++) {
			subArray.push_back(nums[i]);
			backtrack(result, subArray, nums, i + 1);
			subArray.pop_back();
		}
	}
};
