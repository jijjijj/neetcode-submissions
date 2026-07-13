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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        std::stack<TreeNode*> s;
        s.push(root);

        std::unordered_map<TreeNode*, int> heights;

        while (!s.empty()) {
            TreeNode* node = s.top();

            if (node->right && !heights.contains(node->right)) {
                s.push(node->right);
            } else if (node->left && !heights.contains(node->left)) {
                s.push(node->left);
            } else {
                s.pop();

                const int left = heights[node->left];
                const int right = heights[node->right];

                heights[node] = 1 + std::max(left, right);

                if (std::abs(left - right) > 1) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
