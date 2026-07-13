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
        if (!root) return 0;

        std::stack<TreeNode*> s;

        s.push(root);

        int depth = 1;
        int cur_depth = 1;

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            ++cur_depth;

            const size_t size = s.size();
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);

            if (size == s.size()) --cur_depth;

            depth = std::max(depth, cur_depth);
        }

        return depth;
    }
};
