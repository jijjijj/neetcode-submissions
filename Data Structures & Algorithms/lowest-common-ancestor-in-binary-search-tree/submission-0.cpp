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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> s;
        s.push(root);

        if (p->val > q->val) std::swap(p, q);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if ((p->val <= node->val && q->val >= node->val))
                return node;

            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }

        // should never happen
        return nullptr;
    }
};
