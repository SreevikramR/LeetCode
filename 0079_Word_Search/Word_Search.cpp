using namespace std;
#include <vector>
#include <string>

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
		bool doesExist = false;
		vector<char> seq{word[0]};
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == word[0]) {
					used[i][j] = true;
					dfs(board, seq, word, doesExist, i, j, used);
					used[i][j] = false;
				}
			}
		}
		return doesExist;
	}

	void dfs(vector<vector<char>> &board, vector<char> &seq, string &word, bool &doesExist, int &y, int &x, vector<vector<bool>> &used) {
		if (seq.size() == word.size()) {
			doesExist = true;
			return;
		}
		if (doesExist) return;
		vector<int> dx{-1, 1, 0, 0};
		vector<int> dy{0, 0, 1, -1};
		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (new_x >= 0 && new_y >= 0 && new_y < board.size() && new_x < board[0].size()) {
				if (board[new_y][new_x] == word[seq.size()] && !used[new_y][new_x]) {
					seq.push_back(word[seq.size()]);
					used[new_y][new_x] = true;
					dfs(board, seq, word, doesExist, new_y, new_x, used);
					seq.pop_back();
					used[new_y][new_x] = false;
				}
			}
		}
	}
};
