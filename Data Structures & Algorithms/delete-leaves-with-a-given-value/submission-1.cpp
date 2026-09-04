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
        std::unordered_map<TreeNode*, TreeNode*> parent;
        std::unordered_set<TreeNode*> vis;

        parent[root] = nullptr;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (!node->left && !node->right) {
                if (node->val == target) {
                    if (!parent[node]) return nullptr;

                    if (parent[node]->left == node) {
                        parent[node]->left = nullptr;
                    } else if (parent[node]->right == node) {
                        parent[node]->right = nullptr;
                    }

                    delete node;
                }
            } else if (!vis.contains(node)) {
                s.push(node);
                vis.emplace(node);
                if (node->left) {
                    parent[node->left] = node;
                    s.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    s.push(node->right);
                }
            }
        }

        return root;
    }
};