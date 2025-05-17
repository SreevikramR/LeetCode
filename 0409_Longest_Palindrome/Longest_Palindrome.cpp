#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<string, int> map;
		for (char c : s) {
			string str(1, c);
			if (map.find(str) == map.end()) {
				map[str] = 1;
			} else {
				map[str]++;
			}
		}
		int pairCount = 0;
		bool foundOdd = false;
		for (const auto& pair: map) {
			pairCount += (pair.second / 2) * 2;
			if (!foundOdd) {
				foundOdd = pair.second % 2;
			}
		}
		if (foundOdd) pairCount++;
		return pairCount;
	}
};
