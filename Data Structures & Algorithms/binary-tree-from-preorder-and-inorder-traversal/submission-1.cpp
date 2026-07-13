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
        return build(preorder, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(
        const std::vector<int>& preorder,
        const std::vector<int>& inorder,
        int l, int r) {
        if (l > r) return nullptr;

        int i = std::ranges::find(inorder, preorder[preIndex++]) - inorder.begin();

        TreeNode* root = new TreeNode{ inorder[i] };

        root->left = build(preorder, inorder, l, i - 1);
        root->right = build(preorder, inorder, i + 1, r);

        return root;
    }

    int preIndex = 0;
};
