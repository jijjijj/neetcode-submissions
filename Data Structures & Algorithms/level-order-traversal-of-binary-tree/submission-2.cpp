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
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);

        std::vector<std::vector<int>> res;

        for (int i = 0; i < layers.size(); ++i) {
            res.emplace_back(std::move(layers[i]));
        }

        return res;
    }

private:
    void dfs(TreeNode* node, int level) {
        if (!node) return;

        layers[level].emplace_back(node->val);

        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }

    std::unordered_map<int,
        std::vector<int>> layers;
};
