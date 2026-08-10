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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        std::vector<int> res;

        TreeNode* cur = root;

        while (cur) {
            if (!cur->left) {
                res.emplace_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* next = cur->left;

                while (next->right != cur && next->right) {
                    next = next->right;
                }

                if (!next->right) {
                    next->right = cur;
                    cur = cur->left;
                } else {
                    res.emplace_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return res;
    }
};