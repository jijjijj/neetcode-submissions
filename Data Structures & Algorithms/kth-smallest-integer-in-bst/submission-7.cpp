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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res[k - 1];
    }

private:
    void dfs(TreeNode* node, int k) {
        if (!node) return;

        dfs(node->left, k);

        if (res.size() == k) {
            return;
        }

        res.emplace_back(node->val);

        dfs(node->right, k);
    }

    std::vector<int> res;
};
