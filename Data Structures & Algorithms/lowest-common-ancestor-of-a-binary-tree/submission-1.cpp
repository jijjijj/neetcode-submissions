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
        TreeNode fake;
        fake.left = root;

        build(root, qin, q->val);
        build(root, qin, p->val);

        return find(root);
    }

private:
    bool build(TreeNode* root,
        std::unordered_map<TreeNode*, int>& mp, int val) {
        if (!root) return false;

        if (root->val == val ||
            build(root->left, mp, val) ||
            build(root->right, mp, val)) {
            ++mp[root];

            // std::cout << root->val << " " << mp[root] << std::endl;
            return true;
        }

        return false;
    }

    TreeNode* find(TreeNode* root) {
        if (!root) return nullptr;

        if (qin[root->left] < 2 && qin[root->right] < 2) {
            return root;
        }

        if (qin[root->left] == 2) {
            return find(root->left);
        }

        return find(root->right);
    }

    std::unordered_map<TreeNode*, int> qin;
};