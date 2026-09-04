class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* node = root;

        while (node && node->val != key) {
            parent = node;
            if (key < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        if (!node) return root;

        if (!node->left || !node->right) {
            TreeNode* child = node->left ? node->left : node->right;
            if (!parent) return child;
            if (parent->left == node) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            delete node;
        } else {
            TreeNode* cur = node->right;
            TreeNode* par = nullptr;

            while (cur->left) {
                par = cur;
                cur = cur->left;
            }

            if (par) {
                par->left = cur->right;
                cur->right = node->right;
                cur->left = node->left;
            } else {
                node->right->left = node->left;
                cur = node->right;
            }
            delete node;

            if (!parent) return cur;

            // cur
            if (parent->left == node) {
                parent->left = cur;
            } else {
                parent->right = cur;
            }
        }

        return root;
    }
};