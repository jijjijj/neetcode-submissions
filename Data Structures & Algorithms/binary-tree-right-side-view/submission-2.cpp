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
        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<int> result;

        while (!q.empty()) {
            TreeNode* most_right = nullptr;
            for (size_t i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    most_right = node;

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            if (most_right) {
                result.emplace_back(most_right->val);
            }
        }

        return result;
    }
};
