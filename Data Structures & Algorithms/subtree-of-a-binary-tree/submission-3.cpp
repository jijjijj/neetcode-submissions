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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return issub(root, subRoot, subRoot);
    }

private:
    bool issub(TreeNode* root, TreeNode* subRoot, TreeNode* orig) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;

        if (root->val == subRoot->val) {
            const bool is = issub(root->left, subRoot->left, orig) &&
                issub(root->right, subRoot->right, orig);

            if (is) return true;
        }

        return issub(root->left, orig, orig) ||
            issub(root->right, orig, orig);
    }
};
