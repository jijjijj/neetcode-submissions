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

        find(root, p->val, q->val, 0);

        return res;
    }

private:
    void find(TreeNode* root, int p, int q, int depth) {
        if (!root || res) return;

        find(root->left, p, q, depth + 1);

        if (!found1 && (root->val == p || root->val == q)) {
            found1 = root;
        }

        if (found1 && depth <= d) {
            d = depth;
            highest = root;
        }

        if (found1 != root && (root->val == p || root->val == q)) {
            res = highest;
        }

        find(root->right, p, q, depth + 1);
    }

    TreeNode* found1 = nullptr;
    int d = std::numeric_limits<int>::max();
    TreeNode* highest = nullptr;
    TreeNode* res = nullptr;
};