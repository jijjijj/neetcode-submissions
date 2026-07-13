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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;

        dfs(root, result);

        return result;
    }

private:
    void dfs(TreeNode* node, std::vector<int>& result) const {
        if (!node) return;

        result.emplace_back(node->val);

        dfs(node->left, result);
        dfs(node->right, result);
    }
};