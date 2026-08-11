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
        _k = k;
        dfs(root, k);
        return res;
    }

private:
    void dfs(TreeNode* node, int k) {
        if (!node) return;

        dfs(node->left, k);

        if (_k) {
            if (!--_k) res = node->val;
        } else {
            return;
        }

        dfs(node->right, k);
    }

    int _k = 0;
    int res = {};
};
