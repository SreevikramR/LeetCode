class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        std::queue<std::pair<int, int>> q;
        int fresh_oranges = 0;

        // 1. Count fresh oranges and find initial rotten ones
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    fresh_oranges++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        if (fresh_oranges == 0) return 0;

        int time = 0;
        const std::vector<int> d_r = {-1, 1, 0, 0};
        const std::vector<int> d_c = {0, 0, -1, 1};

        while (!q.empty() && fresh_oranges > 0) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                std::pair<int, int> rotten_orange = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int new_row = rotten_orange.first + d_r[j];
                    int new_col = rotten_orange.second + d_c[j];

                    if (new_row >= 0 && new_row < grid.size() &&
                        new_col >= 0 && new_col < grid[0].size() &&
                        grid[new_row][new_col] == 1) {

                        grid[new_row][new_col] = 2;
                        q.push({new_row, new_col});
                        fresh_oranges--;
                    }
                }
            }
            time++;
        }

        return fresh_oranges == 0 ? time : -1;
    }
};
