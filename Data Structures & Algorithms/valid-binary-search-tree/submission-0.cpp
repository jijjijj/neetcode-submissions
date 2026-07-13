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
    bool isValidBST(TreeNode* root) {
        return isValid(root,
            std::numeric_limits<int>::max(),
            std::numeric_limits<int>::min());
    }

private:
    bool isValid(TreeNode* node, int less, int greater) {
        if (!node) return true;
        if (node->val >= less) return false;
        if (node->val <= greater) return false;

        return isValid(node->left, std::min(less, node->val), greater) &&
            isValid(node->right, less, std::max(greater, node->val));
    }
};
