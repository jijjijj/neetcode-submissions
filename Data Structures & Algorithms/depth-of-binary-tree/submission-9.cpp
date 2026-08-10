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
    int maxDepth(TreeNode* root) {
        int depth = 0;

        std::stack<std::pair<TreeNode*, int>> s;
        if (root) s.push({ root, 1 });

        while (!s.empty()) {
            auto [node, d] = s.top();
            s.pop();

            depth = std::max(depth, d);

            if (node->left) s.push({ node->left, d + 1 });
            if (node->right) s.push({ node->right, d + 1 });
        }

        return depth;
    }
};
