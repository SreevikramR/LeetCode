class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<char> strings(200, 0);
        int i = 0;
        for (char c: strs[0]) {
            strings[i] = c;
            i++;
        }
        int maxLength = i;
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            for (char c: strs[i]) {
                if (c != strings[j]) {
                    if (j < maxLength) {
                        maxLength = j;
                        continue;
                    }
                }
                j++;
            }
            if (j < maxLength) maxLength = j;
        }

        string final = "";
        for (int i = 0; i < maxLength; i++) final += strings[i];
        return final;
    }
};
