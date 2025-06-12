#include <cmath>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
		priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<>> pq;
		for (auto point: points) {
			pq.push({sqrt(pow(point[0], 2) + pow(point[1], 2)), point});
		}

		vector<vector<int>> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(pq.top().second);
			pq.pop();
		}
		return ans;
	}
};
