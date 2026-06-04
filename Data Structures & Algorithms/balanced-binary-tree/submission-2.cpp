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
    bool isBalanced(TreeNode* root) {
        bool bal = true;
        depth(root, bal);
        return bal;
    }
    int depth(TreeNode* root, bool& bal) {
        if (!root) return 0;
        if (std::abs(depth(root->left, bal) - depth(root->right, bal)) > 1) {
            bal=false;
        }
        return 1 + std::max(depth(root->left, bal), depth(root->right, bal));
    }
};
