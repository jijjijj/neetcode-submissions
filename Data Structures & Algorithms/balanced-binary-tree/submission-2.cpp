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
    bool isBalanced(TreeNode* root) {
        std::unordered_map<TreeNode*, int> height;

        std::stack<std::pair<TreeNode*, bool>> s; // <node, are children processed?>
        s.push({ root, false });

        while (!s.empty()) {
            const auto [v, done] = s.top();
            s.pop();
            
            if (!v) continue;

            if (done) {
                if (std::abs(height[v->left] -
                    height[v->right]) > 1) return false;
                
                height[v] = std::max(height[v->left], height[v->right]) + 1;
            } else {
                s.push({ v, true });
                s.push({ v->left, false });
                s.push({ v->right, false });
            }
        }

        return true;
    }
};
