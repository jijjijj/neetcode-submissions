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
        if (!root) return 0;

        std::queue<std::pair<TreeNode*, int>> q;
        q.push({ root, root->val });

        int good = 0;
        while (!q.empty()) {
            auto [node, max] = q.front();
            q.pop();

            if (max <= node->val) ++good;

            if (node->left) q.push({ node->left,
                std::max(max, node->left->val) });
            if (node->right) q.push({ node->right,
                std::max(max, node->right->val) });
        }

        return good;
    }
};
