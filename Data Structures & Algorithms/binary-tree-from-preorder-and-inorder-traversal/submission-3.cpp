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
        return build(preorder, inorder, std::numeric_limits<int>::max());
    }

private:
    TreeNode* build(
        const std::vector<int>& preorder,
        const std::vector<int>& inorder,
        int limit) {
        if (pre >= preorder.size()) return nullptr;
        if (inorder[in] == limit) {
            ++in;
            return nullptr;
        }

        TreeNode* root = new TreeNode{ preorder[pre++] };

        root->left = build(preorder, inorder, root->val);
        root->right = build(preorder, inorder, limit);

        return root;
    }

    int pre = 0;
    int in = 0;
};
