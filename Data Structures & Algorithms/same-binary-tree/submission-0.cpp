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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return !p && !q;

        std::stack<TreeNode*> s1;
        std::stack<TreeNode*> s2;

        s1.push(p);
        s2.push(q);

        while (!s1.empty()) {
            TreeNode* n1 = s1.top();
            TreeNode* n2 = s2.top();

            s1.pop();
            s2.pop();

            if (n1->val != n2->val) return false;

            if (n1->left && n2->left) {
                s1.push(n1->left);
                s2.push(n2->left);
            } else if (n1->left || n2->left) {
                return false;
            }

            if (n1->right && n2->right) {
                s1.push(n1->right);
                s2.push(n2->right);
            } else if (n1->right || n2->right) {
                return false;
            }
        }

        return true;
    }
};
