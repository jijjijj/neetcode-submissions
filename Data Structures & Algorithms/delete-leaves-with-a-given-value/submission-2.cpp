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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        std::stack<TreeNode*> s;
        TreeNode* visited = nullptr;
        TreeNode* cur = root;

        while (!s.empty() || cur) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            if (cur->right && cur->right != visited) {
                cur = cur->right;
                continue;
            }
            
            s.pop();
            if (!cur->left && !cur->right) {
                if (cur->val == target) {
                    if (s.empty()) return nullptr;
                    TreeNode* parent = s.top();

                    if (parent->left == cur) {
                        parent->left = nullptr;
                    } else if (parent->right == cur) {
                        parent->right = nullptr;
                    }

                    delete cur;
                }
            }

            visited = cur;
            cur = nullptr;
        }

        return root;
    }
};