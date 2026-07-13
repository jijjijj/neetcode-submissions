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
    int maxPathSum(TreeNode* root) {
        int result = std::numeric_limits<int>::min();
        dfs(root, result);
        return result;
    }

private:
    int dfs(TreeNode* root, int& result) const {
        if (!root) return 0;

        int left = dfs(root->left, result);
        int right = dfs(root->right, result);

        result = std::max(result, left + right + root->val);

        return std::max(0, std::max(left, right) + root->val);
    }
};
