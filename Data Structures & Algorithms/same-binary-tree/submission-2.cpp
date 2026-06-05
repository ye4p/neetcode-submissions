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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;
        if (p) q1.push(p);
        if (q) q2.push(q);
        if ((p==nullptr && q!=nullptr) || p!=nullptr && q==nullptr) return false;

        while (!q1.empty() && !q2.empty()) {
            int size1=q1.size();
            int size2=q2.size();
            if (size1!=size2) return false;
            for (int i=0; i< size1; i++) {
                TreeNode* node1 = q1.front();
                q1.pop();
                TreeNode* node2 = q2.front();
                q2.pop();
                if (node1->val!=node2->val) return false;

                if (node1->left) {
                    q1.push(node1->left);
                }
                if (node1->right) {
                    q1.push(node1->right);
                }

                if (node2->left) {
                    q2.push(node2->left);
                }
                if (node2->right) {
                    q2.push(node2->right);
                }



                if (((node1->left == nullptr && node2->left != nullptr) || (node1->left != nullptr && node2->left == nullptr)) || 
                    ((node1->right == nullptr && node2->right != nullptr) || (node1->right != nullptr && node2->right == nullptr) )
                ) return false;
            }
        }
        if (q1.empty() != q2.empty()) return false;
        return true;
    }
};
