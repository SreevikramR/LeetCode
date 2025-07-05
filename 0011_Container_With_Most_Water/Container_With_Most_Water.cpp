#include <algorithm>
using namespace std;
#include <vector>

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int max = (right - left) * min(height[right], height[left]);
		while (right > left) {
			if (height[right] > height[left]) {
				max = std::max(max, (right - left) * height[left]);
				left++;
			} else {
				max = std::max(max, (right - left) * height[right]);
				right--;
			}
		}
		return max;
	}
};
