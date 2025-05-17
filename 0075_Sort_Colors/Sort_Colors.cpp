class Solution {
public:
	void sortColors(std::vector<int>& nums) {
		std::vector<int> map(3, 0);
		for (int i = 0; i < nums.size(); i++) {
			map[nums[i]] = map[nums[i]] + 1;
		}

		int index = 0;
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i]; j++) {
				nums[index] = i;
				index++;
			}
		}
	}
};
