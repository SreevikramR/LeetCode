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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (!root->left || !root->right) return false;
        return isSameTree(root->left, root->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        if (p->val == q->val) {
            bool res1 = isSameTree(p->left, q->right);
            bool res2 = isSameTree(p->right, q->left);
            if (res2 && res1) return true;
            else return false;
        }
        return true;
    }
};
