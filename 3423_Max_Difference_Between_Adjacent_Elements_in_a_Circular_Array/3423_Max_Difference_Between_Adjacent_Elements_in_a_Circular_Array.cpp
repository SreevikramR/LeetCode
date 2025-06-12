class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (abs(nums[i] - nums[i + 1]) > maxDiff) maxDiff = abs(nums[i] - nums[i + 1]);
        }
        if (abs(nums[0] - nums[nums.size() - 1]) > maxDiff) return abs(nums[0] - nums[nums.size() - 1]);
        return maxDiff;
    }
};
