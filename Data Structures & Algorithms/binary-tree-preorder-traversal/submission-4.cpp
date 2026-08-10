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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        
        TreeNode* cur = root;

        while (cur) {
            if (!cur->left) {
                res.emplace_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;

                while (prev->right != cur && prev->right) {
                    prev = prev->right;
                }

                if (prev->right) {
                    prev->right = nullptr;
                    cur = cur->right;
                } else {
                    res.emplace_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                }
            }
        }
        
        return res;
    }
};