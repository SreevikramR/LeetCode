/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vec;
		if (!root) return vec;
        queue<TreeNode*> queue;
		queue.push(root);
		int nodesOnLevel = 1;
		int level = 0;
		while (!queue.empty()) {
            vec.push_back(vector<int>());
			for (int i = 0; i < nodesOnLevel; i++) {
				TreeNode* curr = queue.front();
				vec[level].push_back(curr->val);
				if (curr->left) queue.push(curr->left);
				if (curr->right) queue.push(curr->right);
				queue.pop();
			}
			nodesOnLevel = queue.size();
			level++;
		}
		return vec;
	}
};
