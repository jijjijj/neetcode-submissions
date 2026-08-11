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
    int result = -1, count = 0;
    void helper(TreeNode* node, int k){
        if(!node) return;

        helper(node->left, k);

        count++;
        if(count == k){
            result = node->val;
            return;
        }
        // if(result != -1){
        //     return;
        // }

        helper(node->right, k);


    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return result;
    }
};
