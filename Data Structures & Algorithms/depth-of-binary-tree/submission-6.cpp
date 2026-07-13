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

        std::queue<TreeNode*> q;

        q.push(root);

        int depth = 0;

        while (!q.empty()) {
            for (size_t i = 0; i < q.size(); ++i) {
                auto node = q.front();
                q.pop();

                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }

            ++depth;
        }

        return depth;
    }
};
