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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        std::vector<std::vector<int>> result;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            std::vector<int> layer;
            layer.reserve(q.size());

            for (size_t i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                layer.emplace_back(node->val);
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.emplace_back(std::move(layer));
        }

        return result;
    }
};
