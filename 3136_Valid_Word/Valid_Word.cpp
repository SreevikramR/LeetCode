#include <cctype>
using namespace std;
#include <string>

class Solution {
public:
	bool isValid(string word) {
		if (word.size() < 3) return false;
		bool containsVowel = false;
		bool containsConsonant = false;
		for (int i = 0; i < word.size(); i++) {
			if (!isalnum(word[i])) return false;
			char letter = tolower(word[i]);
			if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') containsVowel = true;
			else if (isalpha(letter)) containsConsonant = true;
		}
		return containsVowel && containsConsonant;
	}
};
