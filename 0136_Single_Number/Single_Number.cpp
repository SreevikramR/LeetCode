class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, bool> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                map.erase(nums[i]);
            } else {
                map[nums[i]] = true;
            }
        }

        for (const auto& pair : map) {
            return pair.first;
        }
        return 0;
    }
};
