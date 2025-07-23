using namespace std;
#include <string>
#include <stack>

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string high_prio_pair = (x > y) ? "ab" : "ba";
        string low_prio_pair = (x > y) ? "ba" : "ab";
        int high_prio_score = max(x, y);
        int low_prio_score = min(x, y);

        string string_after_first_pass;
        for (char c : s) {
            if (!string_after_first_pass.empty() &&
                string_after_first_pass.back() == high_prio_pair[0] &&
                c == high_prio_pair[1]) {

                string_after_first_pass.pop_back();
                totalScore += high_prio_score;
            } else {
                string_after_first_pass.push_back(c);
            }
        }
        string final_string;
        for (char c : string_after_first_pass) {
            if (!final_string.empty() &&
                final_string.back() == low_prio_pair[0] &&
                c == low_prio_pair[1]) {

                final_string.pop_back();
                totalScore += low_prio_score;
            } else {
                final_string.push_back(c);
            }
        }

        return totalScore;
    }
};
