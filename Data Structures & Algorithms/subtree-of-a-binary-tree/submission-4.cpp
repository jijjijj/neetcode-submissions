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

#include <ranges>

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        const std::vector<int> r = serialize(root);
        const std::vector<int> sr = serialize(subRoot);

        return !std::ranges::search(r, sr).empty();
    }

private:
    std::vector<int> serialize(TreeNode* root) {
        std::vector<int> res;

        std::stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            auto node = s.top();
            s.pop();

            res.emplace_back(node ? node->val : -101);

            if (node) {
                s.push(node->right);
                s.push(node->left);
            }
        }

        return res;
    }
};
