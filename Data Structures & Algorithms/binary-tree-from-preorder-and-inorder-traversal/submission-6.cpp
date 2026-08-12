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
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, preorder.size() - 1);
    }

private:
    TreeNode* build(
        const vector<int>& preorder,
        const vector<int>& inorder, int i) {
        if (p > i) return nullptr;

        TreeNode* root = new TreeNode{ preorder[p] };

        const int pos = mp[preorder[p]];
        ++p;

        root->left = build(
            preorder, inorder, pos);
        root->right = build(
            preorder, inorder, i);

        return root;
    }

    std::unordered_map<int, int> mp;
    int p = 0;
};
