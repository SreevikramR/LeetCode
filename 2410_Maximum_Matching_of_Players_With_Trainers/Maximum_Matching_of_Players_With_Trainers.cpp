using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
	int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
		sort(players.begin(), players.end());
		sort(trainers.begin(), trainers.end());
		reverse(players.begin(), players.end());
		reverse(trainers.begin(), trainers.end());
		int count = 0;
		int player_index = 0;
		int trainer_index = 0;
		while (player_index < players.size() && trainer_index < trainers.size()) {
			if (players[player_index] <= trainers[trainer_index]) {
				count++;
				player_index++;
				trainer_index++;
			} else {
				player_index++;
			}
		}
		return count;
	}
};
