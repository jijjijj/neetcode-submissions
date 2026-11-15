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
        std::unordered_map<TreeNode*, int> height;

        std::stack<TreeNode*> s; // <node, are children processed?>
        TreeNode* node = root;
        TreeNode* last_proc = nullptr;

        while (!s.empty() || node) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top();

                if (!node->right || node->right == last_proc) {
                    s.pop();

                    const int left = height[node->left];
                    const int right = height[node->right];

                    if (std::abs(left - right) > 1)
                        return false;
                    
                    height[node] = std::max(left, right) + 1;

                    last_proc = node;
                    node = nullptr;
                } else {
                    node = node->right;
                }
            }
        }

        return true;
    }
};
