class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
		int start = 0;
		int max_len = 0;
		for (int i = 0; i < s.size(); i++) {
			if (map.find(s[i]) != map.end() && map[s[i]] >= start) {
                start = map[s[i]] + 1;
            }
            map[s[i]] = i;
            max_len = max(max_len, i - start + 1);
		}
		return max_len;
    }
};
