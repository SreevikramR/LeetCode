class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> vec;
        int i = 0;
        int n = intervals.size();

        while (i < n && newInterval[0] > intervals[i][1]) {
            vec.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        vec.push_back(newInterval);

        while (i < n) {
            vec.push_back(intervals[i]);
            i++;
        }

        return vec;
    }
};
