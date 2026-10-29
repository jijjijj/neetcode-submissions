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
    int minDiffInBST(TreeNode* root) {
        int answer = std::numeric_limits<int>::max();

        std::stack<TreeNode*> s;
        TreeNode* cur = root;
        int last = 2 * 10e5 + 1;

        while (!s.empty() || cur) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }

            TreeNode* node = s.top();
            s.pop();

            answer = std::min(answer,
                std::abs(last - node->val));

            last = node->val;

            cur = node->right;
        }
        
        return answer;
    }
};