using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return vector<string>();
		unordered_map<char, vector<char>> letterMap;
		letterMap['2'] = vector<char>{'a', 'b', 'c'};
		letterMap['3'] = vector<char>{'d', 'e', 'f'};
		letterMap['4'] = vector<char>{'g', 'h', 'i'};
		letterMap['5'] = vector<char>{'j', 'k', 'l'};
		letterMap['6'] = vector<char>{'m', 'n', 'o'};
		letterMap['7'] = vector<char>{'p', 'q', 'r', 's'};
		letterMap['8'] = vector<char>{'t', 'u', 'v'};
		letterMap['9'] = vector<char>{'w', 'x', 'y', 'z'};
		string s;
		vector<string> combinations;
		backtrack(digits, letterMap, s, combinations);
		return combinations;
	}

	void backtrack(string &digits, unordered_map<char, vector<char>> &letterMap, string &s, vector<string> &combinations) {
		if (digits.size() == s.size()) {
			combinations.push_back(s);
			return;
		}
		char number = digits[s.size()];
		for (int i = 0; i < letterMap[number].size(); i++) {
			s.push_back(letterMap[number][i]);
			backtrack(digits, letterMap, s, combinations);
			s.pop_back();
		}
	}
};
