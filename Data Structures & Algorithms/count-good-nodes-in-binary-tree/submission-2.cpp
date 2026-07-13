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
        std::stack<std::pair<TreeNode*, int>> s; // node, max_val_in_path
        s.push(std::pair{ root, root->val });

        int result = 0;

        while (!s.empty()) {
            auto [node, max] = s.top();
            s.pop();

            result += (node->val >= max);

            if (node->left)
                s.push(std::pair{ node->left, std::max(max, node->left->val) });
            if (node->right)
                s.push(std::pair{ node->right, std::max(max, node->right->val) });
        }

        return result;
    }
};
