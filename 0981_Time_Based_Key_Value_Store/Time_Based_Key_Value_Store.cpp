using namespace std;
#include <vector>
#include <unordered_map>
#include <string>

class TimeMap {
public:
	unordered_map<string, vector<pair<int, string>>> map;
	TimeMap() {}

	void set(string key, string value, int timestamp) {
		pair<int, string> item{timestamp, value};
		map[key].push_back(item);
	}

	string get(string key, int timestamp) {
		// for (pair<int, string> pair: map[key]) {
		for (int i = map[key].size() - 1; i >= 0; i--) {
			pair<int, string> pair = map[key][i];
			if (pair.first == timestamp) return pair.second;
			else if (pair.first < timestamp) return pair.second;
		}
		return "";
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
