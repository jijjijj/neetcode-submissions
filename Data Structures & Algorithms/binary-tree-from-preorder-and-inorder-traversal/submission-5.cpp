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

        return build(std::span{ preorder },
            std::span{ inorder }, 0);
    }

private:
    TreeNode* build(
        const std::span<int>& preorder,
        const std::span<int>& inorder,
        int inorder_offset) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode{ preorder[0] };

        const int pos = mp[preorder[0]] - inorder_offset;

        root->left = build(
            std::span{ preorder.begin() + 1,
                preorder.begin() + pos + 1 },
            std::span{ inorder.begin(), inorder.begin() + pos },
            inorder_offset
        );
        root->right = build(
            std::span{ preorder.begin() + pos + 1, preorder.end() },
            std::span{ inorder.begin() + pos + 1,
                inorder.end() },
            inorder_offset + pos + 1
        );

        return root;
    }

    std::unordered_map<int, int> mp;
};
