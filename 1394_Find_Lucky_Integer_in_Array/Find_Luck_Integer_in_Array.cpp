using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
	int findLucky(vector<int>& arr) {
		unordered_map<int, int> map;
		for (int i: arr) {
			map[i]++;
		}
		int count = -1;
		for (int i = 1; i <= map.size(); i++) {
			if (map[i] == i) count = i;
		}
		return count;
	}
};
