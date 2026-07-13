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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode fake{};
        TreeNode* curr = &fake;

        int i = 0;
        int j = 0;
        const int n = preorder.size();

        while (i < n && j < n) {
            curr->right = new TreeNode{ preorder[i], nullptr, curr->right };
            curr = curr->right;

            ++i;
            while (i < n && curr->val != inorder[j]) {
                curr->left = new TreeNode{ preorder[i], nullptr, curr };
                curr = curr->left;
                ++i;
            }

            ++j;
            while (j < n && curr->right && curr->right->val == inorder[j]) {
                TreeNode* temp = curr->right;
                curr->right = nullptr;
                curr = temp;
                ++j;
            }
        }

        return fake.right;
    }
};
