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

        TreeNode* cur = root;
        int last = answer;

        while (cur) {
            if (!cur->left) {
                answer = std::min(answer,
                    std::abs(last - cur->val));
                last = cur->val;
                cur = cur->right;
            } else {
                TreeNode* tmp = cur->left;
                while (tmp->right &&
                    tmp->right != cur) {
                    tmp = tmp->right;
                }

                if (tmp->right) {
                    answer = std::min(answer,
                        std::abs(last - cur->val));
                    last = cur->val;
                    cur = tmp->right->right;
                    tmp->right = nullptr;
                } else {
                    last = cur->val;
                    tmp->right = cur;
                    cur = cur->left;
                }
            }
        }
        
        return answer;
    }
};