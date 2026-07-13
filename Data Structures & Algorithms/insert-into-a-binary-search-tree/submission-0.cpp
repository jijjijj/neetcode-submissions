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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode{val};
        
        TreeNode* cur = root;
        TreeNode* last = root;

        while (cur) {
            last = cur;

            if (val > cur->val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }

        if (last->val > val) {
            last->left = new TreeNode{val};
        } else {
            last->right = new TreeNode{val};
        }

        return root;
    }
};