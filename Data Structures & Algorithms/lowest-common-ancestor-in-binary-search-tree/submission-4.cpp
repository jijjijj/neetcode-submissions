
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) std::swap(p, q);

        TreeNode* node = root;

        while (node) {
            if (node->val >= p->val && node->val <= q->val) {
                return node;
            }

            if (node->val > q->val) node = node->left;
            if (node->val < p->val) node = node->right;
        }

        return nullptr;
    }
};