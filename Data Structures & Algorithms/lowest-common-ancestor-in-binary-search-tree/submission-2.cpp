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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) std::swap(p, q);

        std::queue<TreeNode*> q_;
        q_.push(root);

        while (!q_.empty()) {
            TreeNode* node = q_.front();
            q_.pop();

            if (node->val >= p->val && node->val <= q->val) {
                return node;
            }

            if (node->val > q->val) q_.push(node->left);
            if (node->val < p->val) q_.push(node->right);
        }

        return nullptr;
    }
};
