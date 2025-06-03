class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;

        while (pos < n && nums[pos] < 0) {
            pos++;
        }

        int neg = pos - 1;
        vector<int> sorted;

        while (neg >= 0 && pos < n) {
            if (abs(nums[neg]) < nums[pos]) {
                sorted.push_back(nums[neg] * nums[neg]);
                neg--;
            } else {
                sorted.push_back(nums[pos] * nums[pos]);
                pos++;
            }
        }

        while (neg >= 0) {
            sorted.push_back(nums[neg] * nums[neg]);
            neg--;
        }

        while (pos < n) {
            sorted.push_back(nums[pos] * nums[pos]);
            pos++;
        }

        return sorted;
    }
};
