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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        std::vector<int> res;

        std::stack<TreeNode*> q;
        TreeNode* last = root;

        while (!q.empty() || last) {
            while (last) {
                q.push(last);
                last = last->left;
            }

            TreeNode* node = q.top();
            q.pop();

            res.emplace_back(node->val);
            last = node->right;
        }

        return res;
    }
};