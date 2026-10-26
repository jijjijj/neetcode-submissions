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
    TreeNode* buildTree(vector<int>& inorder,
        vector<int>& postorder) {
        const int last = postorder.size() - 1;

        for (int i = 0; i <= last; ++i) {
            mp[inorder[i]] = i;
        }

        return build(0, last, 0, last,
            inorder, postorder);
    }

private:
    TreeNode* build(int i1, int i2, int p1, int p2,
        vector<int>& inorder,
        vector<int>& postorder) {
         if (i1 > i2 || p1 > p2) return nullptr;

        const int val = postorder[p2];
        const int right = i2 - mp[val];

        TreeNode* node = new TreeNode{ val };

        node->left = build(i1, mp[val] - 1,
            p1, p2 - right - 1, inorder, postorder);
        node->right = build(mp[val] + 1, i2,
            p2 - right, p2 - 1, inorder, postorder);

        return node;
    }

    std::unordered_map<int, int> mp;
};