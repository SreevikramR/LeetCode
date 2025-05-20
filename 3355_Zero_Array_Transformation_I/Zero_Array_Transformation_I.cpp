class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diffArray(nums.size() + 1, 0);
        for (int i = 0; i < queries.size(); i++) {
            diffArray[queries[i][0]] -= 1;
            diffArray[queries[i][1] + 1] += 1;
        }

        int diff = 0;
        for (int i = 0; i < nums.size(); i++) {
            diff += diffArray[i];
            if (nums[i] + diff > 0) return false;
        }
        return true;
    }
};
