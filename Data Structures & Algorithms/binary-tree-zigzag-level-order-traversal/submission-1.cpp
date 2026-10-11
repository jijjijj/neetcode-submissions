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
            const int size = q.size();
            std::vector<int> layer(size);

            for (int i = size; i > 0; --i) {
                const TreeNode* v = q.front();
                q.pop();

                const int idx = (res.size() & 1) ? i - 1 : size - i;
                layer[idx] = v->val;

                if (v->left) q.push(v->left);
                if (v->right) q.push(v->right);
            }

            res.emplace_back(std::move(layer));
        }

        return res;
    }
};