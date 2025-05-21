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
    int maxDiameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }

    int height(TreeNode* root) {
        if (!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        int pathLength = left + right;
        if (pathLength > maxDiameter) maxDiameter = pathLength;
        return 1 + max(left, right);
    }
};
