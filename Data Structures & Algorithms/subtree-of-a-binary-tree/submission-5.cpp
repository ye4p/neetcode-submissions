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
    //    if (!root && !subRoot) return true;
    //    if (!root && subRoot) return false; // need to return different answers based on whether they matched at some point or no.
    //    if (root && !subRoot) return false;

    //     if (root->val==subRoot->val) {
    //         if (isSubtree(root->left, subRoot)) return isSubtree(root->left, subRoot);
    //         if (isSubtree(root->right, subRoot)) return isSubtree(root->left, subRoot);
    //         return isSubtree(root->left, subRoot->left) && isSubtree(root->right, subRoot->right);
    //     } else {
    //         return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    //     }
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            for (int i=0; i<s.size(); i++) {
                TreeNode* node=s.top();
                s.pop();
                if (isSameTree(node, subRoot)) return true;
                if (node->left) s.push(node->left);
                if (node->right) s.push(node->right);
            }
        }
        return false;
    }
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root && subRoot) return false;
        if (root && !subRoot) return false;
        if (root->val==subRoot->val) {
            return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right); 
        } else {
            return false;
        }
    }
};
