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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int diameter = 0;

        dfs(root, diameter);

        return diameter;
    }

private:
    int dfs(TreeNode* node, int& diameter) const {
        if (!node) return 0;

        const int left = dfs(node->left, diameter);
        const int right = dfs(node->right, diameter);

        diameter = std::max(diameter, left + right);

        return std::max(left, right) + 1;
    }
};
