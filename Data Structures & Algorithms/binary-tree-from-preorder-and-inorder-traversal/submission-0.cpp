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
        return build(std::span{ preorder.begin(), preorder.end() },
            std::span{ inorder.begin(), inorder.end() });
    }

private:
    TreeNode* build(const span<int>& preorder, const span<int>& inorder) const {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode{ preorder.front() };

        const auto it = std::ranges::find(inorder, preorder.front());
        const size_t size = it - inorder.begin();

        // cassert(it != inorder.end());

        root->left = build(
            std::span{ preorder.begin() + 1, preorder.begin() + 1 + size },
            std::span{ inorder.begin(), it });
        root->right = build(
            std::span{ preorder.begin() + 1 + size, preorder.end() },
            std::span{ it + 1, inorder.end() });

        return root;
    }
};
