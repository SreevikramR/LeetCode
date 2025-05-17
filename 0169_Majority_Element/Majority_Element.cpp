using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int threshold = nums.size() / 2;
		if (nums.size() == 1) return nums[0];
		unordered_map<int, int> map;
		int index = -1;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (map.find(nums[i]) == map.end()) {
				map[nums[i]] = 1;
			} else {
				map[nums[i]]++;
				if (map[nums[i]] > count) {
					index = nums[i];
					count = map[nums[i]];
				}
				if (count > threshold) return index;
			}
		}
		return index;
	}
};
