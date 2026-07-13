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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        std::stack<TreeNode*> s;

        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }

            TreeNode* node = s.top();
            s.pop();

            if (--k == 0) return node->val;
            
            if (node->right) {
                cur = node->right;
            }
        }

        return 0;
    }
};
