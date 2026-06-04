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
    int maxDepth(TreeNode* root) {
        std::queue<TreeNode*> q;
        if (root  !=nullptr)
            q.push(root);
        int level=0;
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; i++) {
                TreeNode* s = q.front();
                q.pop();
                if (s->left !=nullptr)
                    q.push(s->left);
                if (s->right  !=nullptr) 
                    q.push(s->right);
            }
            level++;
        }
        return level;
    }
};

    //      Recursive solution
    // int maxDepth(TreeNode* root) {
    //     if (!root) {
    //         return 0;
    //     }

    //     return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    // }