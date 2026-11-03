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
        std::vector<TreeNode*> q;
        q.emplace_back(root);

        while (!q.empty()) {
            std::vector<TreeNode*> nq;

            int l = 0;
            int r = q.size() - 1;

            while (l <= r) {
                TreeNode* left = q[l];
                TreeNode* right = q[r];
                if ((!left->left ^ !right->right) ||
                    (left->left && left->left->val != right->right->val)) {
                    return false;
                }
                if ((!left->right ^ !right->left) ||
                    (left->right && left->right->val != right->left->val)) {
                    return false;
                }
                ++l;
                --r;
            }

            for (const auto* node : q) {
                if (node->left) nq.emplace_back(node->left);
                if (node->right) nq.emplace_back(node->right);
            }

            q = std::move(nq);
        }

        return true;
    }
};
