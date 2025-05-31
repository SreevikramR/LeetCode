class Solution {
public:
    vector<int> countBits(int n) {
        unordered_map<int, int> map;
        vector<int> bitCount;
        for (int i = 0; i <= n; i++) {
            bitCount.push_back(countBin(i, map));
        }
        return bitCount;
    }

    int countBin(int num, unordered_map<int, int>& map) {
        if (map.find(num >> 1) == map.end()) {
            int oneCount = 0;
            while (num > 0) {
                oneCount += (num & 1);
                num = num >> 1;
            }
            map[num] = oneCount;
            return oneCount;
        } else {
            if (num & 1 == 0) map[num] = map[num >> 1];
            else map[num] = map[num >> 1] + (num & 1);
            return map[num];
        }
    }
};
