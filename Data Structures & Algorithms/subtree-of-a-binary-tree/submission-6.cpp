class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return issub(root, subRoot, subRoot);
    }

private:
    bool issub(TreeNode* root, TreeNode* subRoot, TreeNode* orig) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;

        if (root->val == subRoot->val) {
            const bool is = issub(root->left, subRoot->left, orig) &&
                issub(root->right, subRoot->right, orig);

            if (is) return true;
        }

        if (res.contains(root)) return res[root];

        return res[root] = issub(root->left, orig, orig) ||
            issub(root->right, orig, orig);
    }

    std::unordered_map<TreeNode*, bool> res;
};