#include <print>

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder,
        vector<int>& postorder) {
        const int last = postorder.size() - 1;
        i = last;
        p = last;

        return build(inorder, postorder, -1, -1);
    }

private:
    TreeNode* build(vector<int>& inorder,
        vector<int>& postorder, int par, int par2) {
        if (i < 0 || p < 0) return nullptr;

        const int val = postorder[p];
        TreeNode* node = new TreeNode{ val };

        if (inorder[i] != val) {
            --p;
            node->right = build(inorder, postorder, val, val);
        }
        --i;

        if (i >= 0 && inorder[i] != par) {
            // --i;
            --p;
            node->left = build(inorder, postorder, par, val);
        }

        return node;
    }

    int i = 0;
    int p = 0;
};