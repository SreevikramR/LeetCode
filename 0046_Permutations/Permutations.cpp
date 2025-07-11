using namespace std;
#include <vector>

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> current_permutation;
		vector<bool> used(nums.size(), false);
		vector<vector<int>> all_permutations;
		backtrack(current_permutation, used, all_permutations, nums);
		return all_permutations;
	}

	void backtrack(vector<int>& current_permutation, vector<bool>& used, vector<vector<int>>& all_permutations, vector<int>& nums) {
		if (nums.size() == current_permutation.size()) all_permutations.push_back(current_permutation);
		for (int i = 0; i < nums.size(); i++) {
			if (!used[i]) {
				current_permutation.push_back(nums[i]);
				used[i] = true;
				backtrack(current_permutation, used, all_permutations, nums);
				current_permutation.pop_back();
				used[i] = false;
			}
		}
	}
};
