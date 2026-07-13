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
        for (int i = 0; i < inorder.size(); ++i) indices[inorder[i]] = i;
        
        return build(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(
        const std::vector<int>& preorder,
        int l, int r) {
        if (l > r) return nullptr;

        const int val = preorder[preIndex++];
        const int i = indices[val];

        TreeNode* root = new TreeNode{ val };

        root->left = build(preorder, l, i - 1);
        root->right = build(preorder, i + 1, r);

        return root;
    }

    std::unordered_map<int, int> indices;
    int preIndex = 0;
};
