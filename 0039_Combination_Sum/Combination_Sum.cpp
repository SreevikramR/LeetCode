using namespace std;
#include <vector>

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> nums;
		int sum = 0;
		backtrack(nums, sum, candidates, target, result);
		return result;
	}

	void backtrack(vector<int>& nums, int& sum, vector<int>& candidates, int& target, vector<vector<int>>& result) {
		if (sum == target) result.push_back(nums);
		for (int i = 0; i < candidates.size(); i++) {
			if (sum + candidates[i] <= target && ((!nums.empty() && candidates[i] >= nums.back()) || nums.empty())) {
				sum += candidates[i];
				nums.push_back(candidates[i]);
				backtrack(nums, sum, candidates, target, result);
				sum -= candidates[i];
				nums.pop_back();
			}
		}
	}
};
