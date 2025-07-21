using namespace std;
#include <string>

class Solution {
public:
	string makeFancyString(string s) {
		string result;
        for (int i = 0; i < s.size(); ++i) {
            int len = result.size();
            if (len >= 2 && result[len - 1] == s[i] && result[len - 2] == s[i]) {
                continue;
            }
            result += s[i];
        }
        return result;
	}
};
