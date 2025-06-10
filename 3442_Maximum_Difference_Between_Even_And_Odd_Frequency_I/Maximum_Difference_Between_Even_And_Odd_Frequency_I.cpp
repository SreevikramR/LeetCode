class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> map;
        for (char c: s) {
            map[c] += 1;
        }
        int oddMax = -1;
        int evenMin = 100;
        for (const auto& key : map) {
            int val = map[key.first];
            if (val % 2 == 1) {
                if (val > oddMax) oddMax = val;
            } else {
                if (val < evenMin) evenMin = val;
            }
        }
        return oddMax - evenMin;
    }
};
