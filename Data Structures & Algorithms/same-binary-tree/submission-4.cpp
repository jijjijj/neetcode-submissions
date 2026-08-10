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
    bool isSameTree(TreeNode* p, TreeNode* v) {
        std::queue<std::pair<TreeNode*, TreeNode*>> q;
        q.push({ p, v });

        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            if ((!a && b) || (a && !b)) return false;
            if (a && b && a->val != b->val) return false;
            if (!a && !b) continue;

            q.push({ a->left, b->left });
            q.push({ a->right, b->right });
        }

        return true;
    }
};
