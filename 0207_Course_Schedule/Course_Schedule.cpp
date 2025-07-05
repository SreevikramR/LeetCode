
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the graph as an adjacency list
        vector<vector<int>> graph(numCourses);
        for (const auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            graph[prereq].push_back(course); // prereq → course
        }

        // States: 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> visitState(numCourses, 0);

        // DFS function to detect cycles
        function<bool(int)> dfs = [&](int course) {
            if (visitState[course] == 1) return false; // Found a cycle
            if (visitState[course] == 2) return true;  // Already checked, safe

            visitState[course] = 1; // Mark as visiting
            for (int neighbor : graph[course]) {
                if (!dfs(neighbor)) return false;
            }
            visitState[course] = 2; // Mark as visited
            return true;
        };

        // Run DFS for each course
        for (int i = 0; i < numCourses; ++i) {
            if (visitState[i] == 0) {
                if (!dfs(i)) return false;
            }
        }

        return true; // No cycles found
    }
};
