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
        std::queue<std::tuple<TreeNode*, int, int>> q; // node, min, max
        q.push({ root,
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::max() });

        while (!q.empty()) {
            auto [node, min, max] = q.front();
            q.pop();

            if (!node) continue;
            if (node->val > max || node->val < min) return false;

            q.push({ node->left, min,
                std::min(max, node->val) });
            q.push({ node->right,
                std::max(min, node->val), max });
        }

        return true;
    }
};
