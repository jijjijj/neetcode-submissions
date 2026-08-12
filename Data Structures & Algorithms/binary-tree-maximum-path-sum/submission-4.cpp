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
    int maxPathSum(TreeNode* root) {
        int ans = std::numeric_limits<int>::min();
        
        std::unordered_map<TreeNode*, int> mp;

        std::stack<std::pair<TreeNode*, bool>> s;
        s.push(std::pair{ root, false });

        while (!s.empty()) {
            auto [node, proc] = s.top();
            s.pop();

            if (!node) continue;

            if (proc) {
                mp[node] = node->val + std::max(std::max(mp[node->left],
                    mp[node->right]), 0);

                ans = std::max(ans, node->val +
                    std::max(mp[node->left], 0) +
                    std::max(mp[node->right], 0));
            } else {
                s.push({ node, true });
                s.push({ node->left, false });
                s.push({ node->right, false });
            }
        }

        return ans;
    }

private:
    int dfs(TreeNode* root, int& max) {
        if (!root) return 0;

        const int left = dfs(root->left, max);
        const int right = dfs(root->right, max);

        const int sum = root->val + std::max(left > right ? left : right, 0);

        max = std::max(max, root->val + std::max(left, 0) + std::max(right, 0));

        return sum;
    }
};
