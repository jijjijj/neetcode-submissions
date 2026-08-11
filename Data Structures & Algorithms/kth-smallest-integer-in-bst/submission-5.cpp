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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;

        while (cur) {
            if (!cur->left) {
                if (!--k) return cur->val;
                cur = cur->right;
            } else {
                TreeNode* next = cur->left;

                while (next->right && next->right != cur) {
                    next = next->right;
                }

                if (next->right) {
                    next->right = nullptr;
                    if (!--k) return cur->val;
                    cur = cur->right;
                } else {
                    next->right = cur;
                    cur = cur->left;
                }
            }
        }

        return -1;
    }
};
