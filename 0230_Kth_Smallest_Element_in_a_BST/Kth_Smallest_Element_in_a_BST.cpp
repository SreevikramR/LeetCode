
using namespace std;
#include <vector>
#include <stack>

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
	int kthSmallest(TreeNode* root, int k) {
		vector<int> values;
		dfs(root, k, values);
		return values[k - 1];
	}

	void dfs(TreeNode* node, int &k, vector<int> &values) {
		if (!node || k < values.size()) return;
		dfs(node->left, k, values);
		values.push_back(node->val);
		dfs(node->right, k, values);
	}
};
