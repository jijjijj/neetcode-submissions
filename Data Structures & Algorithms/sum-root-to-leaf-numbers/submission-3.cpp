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
    int sumNumbers(TreeNode* root) {
        std::stack<std::pair<TreeNode*, int>> s;
        s.push({root, 0});
        int sum = 0;

        while (!s.empty()) {
            auto [node, val] = s.top();
            s.pop();

            val *= 10;
            val += node->val;

            if (!node->left && !node->right) {
                sum += val;
            }

            if (node->right) s.push({ node->right, val });
            if (node->left) s.push({ node->left, val });
        }

        return sum;
    }
};