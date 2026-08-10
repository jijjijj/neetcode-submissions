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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;

        // <node, were children visited>
        std::stack<std::pair<TreeNode*, bool>> s;
        s.push(std::pair{ root, false });

        while (!s.empty()) {
            auto [node, v] = s.top();
            s.pop();

            if (!node) continue;

            if (v) {
                res.emplace_back(node->val);
            } else {
                s.push(std::pair{ node, true });
                s.push(std::pair{ node->right, false });
                s.push(std::pair{ node->left, false });
            }
        }

        return res;
    }
};