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
    int goodNodes(TreeNode* root) {
        return good(root, -101);
    }

private:
    int good(TreeNode* node, int max) {
        if (!node) return 0;

        return (node->val >= max)
            + good(node->left, std::max(node->val, max))
            + good(node->right, std::max(node->val, max));
    }
};
