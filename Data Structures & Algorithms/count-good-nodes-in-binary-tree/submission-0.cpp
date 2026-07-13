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
        int result = 0;

        dfs(root, root->val, result);

        return result;
    }

private:
    void dfs(TreeNode* node, int val, int& result) const {
        if (node->val >= val) ++result;

        if (node->left) dfs(node->left, std::max(val, node->left->val), result);
        if (node->right) dfs(node->right, std::max(val, node->right->val), result);
    }
};
