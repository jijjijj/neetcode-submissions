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

        std::vector<int> result;
        std::stack<TreeNode*> s;
        // s.push(root);
        TreeNode* cur = root;

        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }

            TreeNode* n = s.top();
            s.pop();

            result.emplace_back(n->val);

            cur = n->right;
        }

        return result;
    }
};