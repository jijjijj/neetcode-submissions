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
        TreeNode fake;
        TreeNode* cur = &fake;

        int p = 0;
        int i = 0;

        const int n = preorder.size();

        while (p < n) {
            cur->right = new TreeNode{ preorder[p], nullptr, cur->right };
            cur = cur->right;
            ++p;

            while (p < n && cur->val != inorder[i]) {
                cur->left = new TreeNode{ preorder[p], nullptr, cur };
                cur = cur->left;
                ++p;
            }
            ++i;

            while (cur->right && cur->right->val == inorder[i]) {
                TreeNode* next = cur->right;
                cur->right = nullptr;
                cur = next;
                ++i;
            }
        }

        return fake.right;
    }
};
