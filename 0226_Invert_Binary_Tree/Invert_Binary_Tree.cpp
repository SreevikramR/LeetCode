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
    TreeNode* invertTree(TreeNode* root) {
        flipNodes(root);
        return root;
    }

    void flipNodes(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        if (root->right) flipNodes(root->right);
        if (root->left) flipNodes(root->left);
    }
};
