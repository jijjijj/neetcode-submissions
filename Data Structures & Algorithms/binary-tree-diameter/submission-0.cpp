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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        std::unordered_map<TreeNode*, int> depth;

        dfs(root, depth);

        int diameter = 0;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            diameter = std::max(diameter,
                (node->left ? depth[node->left] + 1 : 0) +
                (node->right ? depth[node->right] + 1 : 0));
            
            // std::cout << node->val << ": left - " << (node->left ? depth[node->left] : 0) <<
            //     ", right - " << (node->right ? depth[node->right] : 0) << std::endl; 

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return diameter;
    }

private:
    int dfs(TreeNode* node, std::unordered_map<TreeNode*, int>& depth) const {
        if (!node) return 0;

        const int left = dfs(node->left, depth);
        const int right = dfs(node->right, depth);

        depth[node] = std::max(left, right);

        return depth[node] + 1;
    }
};
