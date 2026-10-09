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
    int sumNumbers(TreeNode* root) {
        int sum = 0;

        std::vector<int> power(10, 1);
        for (int i = 1; i < power.size(); ++i)
            power[i] = power[i - 1] * 10;

        int num = 0;
        TreeNode* cur = root;

        while (cur) {
            if (!cur->left) {
                num = num * 10 + cur->val;
                if (!cur->right) sum += num;
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                int steps = 1;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                    ++steps;
                }

                if (!prev->right) {
                    prev->right = cur;
                    num = num * 10 + cur->val;
                    cur = cur->left;
                } else {
                    prev->right = nullptr;
                    sum += num;
                    num /= power[steps];
                    cur = cur->right;
                }
            }
        }

        return sum;
    }
};