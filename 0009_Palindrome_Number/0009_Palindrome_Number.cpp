class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        string str = std::to_string(x);
        for (int i = 0; i < (str.size() / 2); i++){
            if (str[i] != str[str.size()-i-1]) {
                return false;
            }
        }
        return true;
    }
};
