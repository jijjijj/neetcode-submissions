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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (isSame(node, subRoot)) return true;

            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }

        return false;
    }

private:
    bool isSame(TreeNode* p, TreeNode* q) const {
        std::stack<std::pair<TreeNode*, TreeNode*>> s;
        s.push(std::pair{ p, q });

        while (!s.empty()) {
            auto [n1, n2] = s.top();
            s.pop();

            if (!n1 && !n2) continue;
            if (!n1 || !n2 || n1->val != n2->val) return false;

            s.push(std::pair{ n1->left, n2->left });
            s.push(std::pair{ n1->right, n2->right });
        }

        return true;
    }
};
