using namespace std;
#include <vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startCol = 0;
        int endCol = matrix[0].size() - 1;
        int startRow = 0;
        int endRow = matrix.size() - 1;
        vector<int> result;
		while (startCol <= endCol && startRow <= endRow) {
			for (int i = startCol; i <= endCol; i++) result.push_back(matrix[startRow][i]);
			for (int i = startRow + 1; i <= endRow; i++) result.push_back(matrix[i][endCol]);
			if (startRow < endRow) for (int i = endCol - 1; i >= startCol; i--) result.push_back(matrix[endRow][i]);
			if (startCol < endCol) for (int i = endRow - 1; i > startRow; i--) result.push_back(matrix[i][startCol]);
			startCol++;
			endCol--;
			startRow++;
			endRow--;
		}
		return result;
    }
};
