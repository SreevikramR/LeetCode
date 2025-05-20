class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, pair<int, char>> map;
        map['I'] = std::make_pair(1, 'Z');
        map['V'] = std::make_pair(5, 'I');
        map['X'] = std::make_pair(10, 'I');
        map['L'] = std::make_pair(50, 'X');
        map['C'] = std::make_pair(100, 'X');
        map['D'] = std::make_pair(500, 'C');
        map['M'] = std::make_pair(1000, 'C');

        char prev = '\0';
        int total = 0;
        for (char c : s) {
            if (map[c].second == prev) total -= (2 * map[prev].first) - map[c].first;
            else total += map[c].first;
            prev = c;
        }
        return total;
    }
};
