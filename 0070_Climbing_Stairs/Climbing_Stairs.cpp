using namespace std;
#include <unordered_map>

class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> map;
        map[1] = 1;
        map[2] = 2;
        return climbRecursive(n, map);
    }

	int climbRecursive(int n, unordered_map<int, int>& map) {
		if (map.find(n) != map.end()) {
			return map[n];
		} else {
			map[n] = climbRecursive(n - 1, map) + climbRecursive(n - 2, map);
			return map[n];
		}
	}
};
