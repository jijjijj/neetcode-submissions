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
    bool isBalanced(TreeNode* root) {
        dfs(root);

        return ans;
    }

private:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        if (!ans) return 0;

        const int left = dfs(root->left);
        const int right = dfs(root->right);

        if (std::abs(left - right) > 1) ans = false;

        return 1 + std::max(left, right);
    }

    bool ans = true;
};
