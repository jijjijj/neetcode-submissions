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
    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {
        const int size = postorder.size();
        int i = size - 1;
        int p = size - 1;

        TreeNode fake{3001};
        TreeNode* last = &fake;

        while (p >= 0) {
            TreeNode* next = last->left;

            last->left = new TreeNode{ postorder[p--], next, nullptr };
            last = last->left;

            while (p >= 0 && inorder[i] != last->val) {
                last->right = new TreeNode{
                        postorder[p], last, nullptr };
                last = last->right;

                --p;
            }

            --i;
            while (i >= 0 && last->left &&
                last->left->val == inorder[i]) {
                TreeNode* tmp = last->left;
                last->left = nullptr;
                last = tmp;
                --i;
            }
        }

        return fake.left;
    }
};