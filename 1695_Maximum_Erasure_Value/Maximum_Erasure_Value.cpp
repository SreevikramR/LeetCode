#include <algorithm>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		int sum = 0;
		int maxSum = 0;
		int start = 0;
		unordered_map<int, bool> map;
		for (int i = 0; i < nums.size(); i++) {
			if (map[nums[i]]) {
				for (int j = start; j < i; j++) {
					sum -= nums[j];
					map[nums[j]] = false;
                    start++;
                    if (nums[j] == nums[i]) break;
				}
			}
            sum += nums[i];
            if (sum > maxSum) maxSum = sum;
            map[nums[i]] = true;
		}
		return max(sum, maxSum);
	}
};
