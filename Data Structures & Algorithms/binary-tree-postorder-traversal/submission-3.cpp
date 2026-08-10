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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;

        TreeNode* cur = root;

        while (cur) {
            if (!cur->right) {
                res.emplace_back(cur->val);
                cur = cur->left;
            } else {
                TreeNode* next = cur->right;

                while (next->left != cur && next->left) {
                    next = next->left;
                }

                if (next->left) {
                    next->left = nullptr;
                    cur = cur->left;
                } else {
                    res.emplace_back(cur->val);
                    next->left = cur;
                    cur = cur->right;
                }
            }
        }

        std::ranges::reverse(res);
        return res;
    }
};