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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode fake(-100001, nullptr, root);
        root = &fake;

        while (root) {
            TreeNode* del = nullptr;
            if (root->left &&
                root->left->val == key) {
                root->left = delet(root->left);
                break;
            } else if (root->right &&
                root->right->val == key) {
                root->right = delet(root->right);
                break;
            }

            if (root->val > key) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return fake.right;
    }

private:
    TreeNode* delet(TreeNode* node) {
        TreeNode* nw = nullptr;
        if (node->right) {
            nw = node->right;
            TreeNode* most_left = nw->left;
            while (most_left && most_left->left)
                most_left = most_left->left;
            if (most_left) most_left->left = node->left;
            else nw->left = node->left;
        } else {
            nw = node->left;
        }

        delete node;
        return nw;
    }
};