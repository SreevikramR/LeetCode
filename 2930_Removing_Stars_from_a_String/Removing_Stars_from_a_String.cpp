class Solution {
public:
    string removeStars(string s) {
        std::string s2;
        for (auto c: s) {
            if (c == '*') s2.pop_back();
            else s2.push_back(c);
        }
        return s2;
    }
};
