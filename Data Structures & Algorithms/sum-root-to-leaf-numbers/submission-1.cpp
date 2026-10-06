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
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});
        int sum = 0;

        while (!q.empty()) {
            auto [node, val] = q.front();
            q.pop();

            val *= 10;
            val += node->val;

            if (!node->left && !node->right) {
                sum += val;
            }

            if (node->left) q.push({ node->left, val });
            if (node->right) q.push({ node->right, val });
        }

        return sum;
    }
};