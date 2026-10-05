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
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }

private:
    int sum(TreeNode* root, int curr) {
        if (!root) return 0;

        curr *= 10;
        curr += root->val;

        if (!root->left && !root->right) return curr;

        return sum(root->left, curr) +
            sum(root->right, curr);
    }
};