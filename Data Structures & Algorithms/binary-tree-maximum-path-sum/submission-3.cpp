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
        int ans = std::numeric_limits<int>::min();
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode* root, int& max) {
        if (!root) return 0;

        const int left = dfs(root->left, max);
        const int right = dfs(root->right, max);

        const int sum = root->val + std::max(left > right ? left : right, 0);

        max = std::max(max, root->val + std::max(left, 0) + std::max(right, 0));

        return sum;
    }
};
