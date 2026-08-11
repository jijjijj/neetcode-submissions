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
    bool dfs(TreeNode* node, int k) {
        if (!node) return true;

        if (res.size() == k) {
            return false;
        }

        if (!dfs(node->left, k)) return false;

        res.emplace_back(node->val);

        return dfs(node->right, k);
    }

    std::vector<int> res;
};
