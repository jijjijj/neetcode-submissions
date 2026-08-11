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
        TreeNode* new_node = new TreeNode{ val };
        if (!root) return new_node;

        TreeNode* node = root;

        while (node) {
            if (node->val < val) {
                if (!node->right) {
                    node->right = new_node;
                    break;
                }
                node = node->right;
            } else {
                if (!node->left) {
                    node->left = new_node;
                    break;
                }
                node = node->left;
            }
        }

        return root;
    }
};