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
    int diameterOfBinaryTree(TreeNode* root) {
        int answer = 0;

        depth(root, answer);

        return answer;
    }

private:
    int depth(TreeNode* node, int& max) {
        if (!node) return 0;

        const int left = !!node->left + depth(node->left, max);
        const int right = !!node->right + depth(node->right, max);

        max = std::max(left + right, max);

        return std::max(left, right);
    } 
};
