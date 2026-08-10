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
        int max = 0;
        std::unordered_map<TreeNode*, int> mx;

        std::stack<std::pair<TreeNode*, bool>> s;
        s.push({ root, false });

        while (!s.empty()) {
            auto [node, v] = s.top();
            s.pop();

            if (!node) continue;

            if (v) {
                const int left = mx[node->left];
                const int right = mx[node->right];
                mx[node] = 1 + std::max(
                    mx[node->left],
                    mx[node->right]);
                max = std::max(max, left + right);
            } else {
                s.push({ node, true });
                s.push({ node->left, false });
                s.push({ node->right, false });
            }
        }

        return max;
    }
};
