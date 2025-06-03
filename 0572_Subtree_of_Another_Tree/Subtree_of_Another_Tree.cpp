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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (!subRoot) return true;
        if (!root) return false;
        queue<TreeNode*> queue;
		queue.push(root);
		while (!queue.empty()) {
			TreeNode* curr = queue.front();
			queue.pop();
			if (curr) {
				if (subRoot->val == curr->val) {
	                if (isSameTree(curr, subRoot)) return true;
	            }
				queue.push(curr->left);
				queue.push(curr->right);
			}
		}
		return false;
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!q || !p) return false;
        if (p->val != q->val) return false;
        if (p->val == q->val) {
            bool res1 = isSameTree(p->left, q->left);
            bool res2 = isSameTree(p->right, q->right);
            if (res2 && res1) return true;
            else return false;
        }
        return true;
    }
};
