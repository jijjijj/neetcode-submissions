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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            std::optional<int> val;

            for (int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();

                if (!node) continue;

                val = node->val;

                q.push(node->left);
                q.push(node->right);
            }

            if (val) res.emplace_back(*val);
        }

        return res;
    }
};
