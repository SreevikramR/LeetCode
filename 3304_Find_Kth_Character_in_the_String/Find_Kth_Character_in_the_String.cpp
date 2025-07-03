class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        int i = 0;
        while (word.size() < k) {
            string current = word;
            for (char c: current) {
                word.push_back(c += 1);
            }
        }
        return word[k - 1];
    }
};
