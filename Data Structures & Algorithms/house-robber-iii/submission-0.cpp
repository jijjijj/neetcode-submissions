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
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return std::max(res.first, res.second);
    }

private:
    std::pair<int, int> // incl root, not incl roo
        dfs(TreeNode* root) {
        if (!root) return {};

        const auto left = dfs(root->left);
        const auto right = dfs(root->right);

        return {
            root->val + left.second + right.second,
            std::max(left.first, left.second) + std::max(right.first, right.second)
        };
    }
};