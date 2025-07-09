using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		stack<pair<int, int>> stack;
		int islandCount = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					stack.push(pair<int, int>{i, j});
					while (!stack.empty()) {
						pair<int, int> top = stack.top();
						stack.pop();
						visited[top.first][top.second] = true;
						int dr[] = {-1, 1, 0, 0};
						int dc[] = {0, 0, -1, 1};
						for (int k = 0; k < 4; i++) {
							int new_r = top.first + dr[k];
							int new_c = top.second + dc[k];
							if (new_r >= 0 && new_c >= 0 && new_r < grid.size() && new_c < grid[0].size() && !visited[new_r][new_c] && grid[new_r][new_c] == '1') {
								stack.push(pair<int, int>{new_r, new_c});
							}
						}
					}
					islandCount++;
				}
			}
		}
		return islandCount;
	}
};
