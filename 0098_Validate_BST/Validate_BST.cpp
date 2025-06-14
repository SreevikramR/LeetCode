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
	bool isValidBST(TreeNode* root) {
		return checkValidSubTree(root, LONG_MIN, LONG_MAX);
	}

	bool checkValidSubTree(TreeNode* root, long min, long max) {
		if (!root) return true;
		if (root->val >= max || root->val <= min) return false;
		bool left = checkValidSubTree(root->left, min, root->val);
		bool right = checkValidSubTree(root->right, root->val, max);
		return (left && right);
	}
};
