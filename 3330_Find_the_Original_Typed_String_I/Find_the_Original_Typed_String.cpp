using namespace std;
#include <string>

class Solution {
public:
	int possibleStringCount(string word) {
		char prev = word[0];
		int count = 1;
		for (int i = 1; i < word.size(); i++) {
			if (word[i] == prev) count++;
			else prev = word[i];
		}
		return count;
	}
};
