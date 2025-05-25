class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); i++) {
            if (map.find(words[i]) == map.end()) {
                map[words[i]] = 1;
            } else {
                map[words[i]]++;
            }
        }

		int pairCount = 0;
		bool foundOdd = false;
        vector<string> keys;
        for (auto& p : map) keys.push_back(p.first);

		for (const string& word : keys) {
            int count = map[word];
            if (!count) continue;
            if (word[0] == word[1]) {
                pairCount += (count / 2) * 4;
                if (!foundOdd && count % 2 == 1) {
                    pairCount += 2;
                    foundOdd = true;
                }
                continue;
			}

            int lower = count;
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (map[rev] < lower) lower = map[rev];

            pairCount = pairCount + (lower * 4);
            map[rev] = 0;
            map[word] = 0;
		}
		return pairCount;
    }
};
