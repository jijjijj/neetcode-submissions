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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int diameter = 0;

        std::stack<TreeNode*> s;
        std::unordered_map<TreeNode*, int> heights;

        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();

            if (node->left && !heights.contains(node->left)) {
                s.push(node->left);
            } else if (node->right && !heights.contains(node->right)) {
                s.push(node->right);
            } else {
                s.pop();

                const int left = heights[node->left];
                const int right = heights[node->right];

                heights[node] = std::max(left, right) + 1;

                diameter = std::max(diameter, left + right);
            }
        }

        return diameter;
    }
};
