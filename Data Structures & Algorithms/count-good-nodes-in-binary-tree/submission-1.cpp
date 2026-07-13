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
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int val) const {
        int result = 0;

        if (node->val >= val) ++result;

        if (node->left) 
            result += dfs(node->left, std::max(val, node->left->val));
        if (node->right)
            result += dfs(node->right, std::max(val, node->right->val));

        return result;
    }
};
