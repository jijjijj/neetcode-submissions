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
    bool isValidBST(TreeNode* root) {
        std::queue<std::tuple<TreeNode*, int, int>> q; // node, less, greater
        q.push(std::tuple{ root,
            std::numeric_limits<int>::max(),
            std::numeric_limits<int>::min() });

        while (!q.empty()) {
            auto [node, less, greater] = q.front();
            q.pop();

            if (!node) continue;
            if (node->val >= less || node->val <= greater) return false;

            q.push(std::tuple{ node->left,
                std::min(node->val, less), greater });
            q.push(std::tuple{ node->right,
                less, std::max(node->val, greater) });
        }

        return true;
    }
};
