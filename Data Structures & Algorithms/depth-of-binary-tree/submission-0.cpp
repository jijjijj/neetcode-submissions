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
        std::stack<TreeNode*> s;

        s.push(root);

        int depth = 0;
        int cur_depth = 1;

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (node) {
                ++cur_depth;

                s.push(node->left);
                s.push(node->right);
            } else {
                --cur_depth;
            }

            depth = std::max(depth, cur_depth);
        }

        return depth;
    }
};
