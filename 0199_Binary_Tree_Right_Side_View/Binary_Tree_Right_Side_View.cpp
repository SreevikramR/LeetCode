using namespace std;
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		dfs(result, 0, root);
		return result;
	}

	void dfs(vector<int> &result, int depth, TreeNode* node) {
		if (!node) return;
		if (depth == result.size()) result.push_back(node->val);
		dfs(result, depth + 1, node->right);
		dfs(result, depth + 1, node->left);
	}
};
