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
class BSTIterator {
public:
    BSTIterator(TreeNode* root)
        : root{ root }, cur{ root } {}
    
    int next() {
        int res = 0;

        if (!s.empty() || cur) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }

            TreeNode* node = s.top();
            s.pop();

            res = node->val;
            cur = node->right;
        }

        return res;
    }
    
    bool hasNext() {
        return !s.empty() || cur;
    }

private:
    TreeNode* root{};
    TreeNode* cur{};
    std::stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */