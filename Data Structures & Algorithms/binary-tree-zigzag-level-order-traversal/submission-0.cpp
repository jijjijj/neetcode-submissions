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
#include <ranges>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        std::vector<std::vector<int>> res;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            std::vector<int> layer;

            for (int i = q.size(); i > 0; --i) {
                const TreeNode* v = q.front();
                q.pop();

                layer.emplace_back(v->val);

                if (v->left) q.push(v->left);
                if (v->right) q.push(v->right);
            }

            if (res.size() & 1) std::ranges::reverse(layer);

            res.emplace_back(std::move(layer));
        }

        return res;
    }
};