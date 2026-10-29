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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        std::stack<std::pair<TreeNode*, int>> s;
        s.push({ root, targetSum - root->val });

        while (!s.empty()) {
            const auto [node, remain] = s.top();
            s.pop();

            if (!remain && !node->left && !node->right) return true;

            if (node->left) s.push({ node->left,
                remain - node->left->val });
            if (node->right) s.push({ node->right,
                remain - node->right->val });
        }

        return false;
    }
};