#include <ranges>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        std::vector<std::vector<int>> res;

        std::stack<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            std::stack<TreeNode*> s;
            
            std::vector<int> layer;

            while (!q.empty()) {
                const TreeNode* v = q.top();
                q.pop();

                TreeNode* first = v->left;
                TreeNode* second = v->right;

                layer.emplace_back(v->val);
                if (res.size() & 1) std::swap(first, second);

                if (first) s.push(first);
                if (second) s.push(second);
            }

            res.emplace_back(std::move(layer));
            q = std::move(s);
        }

        return res;
    }
};