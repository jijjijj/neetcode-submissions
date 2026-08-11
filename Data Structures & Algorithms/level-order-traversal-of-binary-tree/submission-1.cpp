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
        std::vector<std::vector<int>> res;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            std::vector<int> layer;
            for (int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();

                if (!node) continue;

                layer.emplace_back(node->val);

                q.push(node->left);
                q.push(node->right);
            }

            if (!layer.empty()) res.emplace_back(std::move(layer));
        }

        return res;
    }
};
