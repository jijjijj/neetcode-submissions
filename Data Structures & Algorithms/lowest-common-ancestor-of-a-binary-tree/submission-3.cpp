/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
        TreeNode* p, TreeNode* q) {

        find(root, p->val, q->val);

        return res;
    }

private:
    std::pair<bool, bool> find(TreeNode* root, int p, int q) {
        if (!root) return {};

        std::pair<bool, bool> left = find(root->left, p, q);
        std::pair<bool, bool> right = find(root->right, p, q);

        const bool foundp = left.first || right.first ||
            root->val == p;
        const bool foundq = left.second || right.second ||
            root->val == q;

        int result = foundp && foundq;
        if (!res && result) res = root;

        return { foundp, foundq };
    }

    TreeNode* res = nullptr;
};