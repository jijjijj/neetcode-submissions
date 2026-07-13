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
        std::stack<std::pair<TreeNode*, int>> s;

        s.push(std::pair{ root, 1 });

        int depth = 0;

        while (!s.empty()) {
            auto node = s.top();
            s.pop();

            if (node.first) {
                depth = std::max(depth, node.second);

                s.push(std::pair{ node.first->left, node.second + 1 });
                s.push(std::pair{ node.first->right, node.second + 1 });
            }
        }

        return depth;
    }
};
