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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        const std::vector<int> tree = serialize(root);
        const std::vector<int> subtree = serialize(subRoot);

        return zfunction(tree, subtree);
    }

private:
    bool zfunction(const std::vector<int>& haystack,
        const std::vector<int>& needle) const {
        std::vector<int> domain;
        domain.reserve(haystack.size() + needle.size() + 1);

        domain.insert(domain.end(), needle.begin(), needle.end());
        domain.emplace_back(-201);
        domain.insert(domain.end(), haystack.begin(), haystack.end());

        std::vector<int> z(domain.size());

        int l = 0;
        int r = 0;

        for (int i = 1; i < domain.size(); ++i) {
            if (i < r) {
                z[i] = std::min(z[i - l], r - i);
            }

            while (i + z[i] < domain.size() &&
                domain[i + z[i]] == domain[z[i]]) {
                ++z[i];
            }

            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }

            if (z[i] == needle.size()) return true;
        }

        return false;
    }
    std::vector<int> serialize(TreeNode* root) const {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (node) {
                result.emplace_back(node->val);

                s.push(node->left);
                s.push(node->right);
            } else {
                result.emplace_back(-200);
            }
        }

        return result;
    }
};
