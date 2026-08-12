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

#include <ranges>

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 1001);
    }

private:
    TreeNode* build(
        const vector<int>& preorder,
        const vector<int>& inorder, int limit) {
        if (p >= preorder.size()) return nullptr;
        
        if (inorder[i] == limit) {
            ++i;
            return nullptr;
        }

        TreeNode* root = new TreeNode{ preorder[p] };

        ++p;

        root->left = build(
            preorder, inorder, root->val);
        root->right = build(
            preorder, inorder, limit);

        return root;
    }

    int p = 0;
    int i = 0;
};
