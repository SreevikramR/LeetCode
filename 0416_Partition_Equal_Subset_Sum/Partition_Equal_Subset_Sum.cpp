using namespace std;
#include <vector>

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int num: nums) sum += num;
		if (sum % 2 == 1) return false;
		int target = sum / 2;
		vector<bool> dp(target + 1, false);
		dp[0] = true;
		for (int num: nums) {
			for (int i = target; i >= num; i--) {
				if (dp[i - num]) {
					dp[i] = true;
				}
			}
		}
		return dp[target];
	}
};
