class Solution {
public:
    int goodNodes(TreeNode* root) {
        std::stack<std::pair<TreeNode*, int>> s; // node, max_val_in_path
        s.push(std::pair{ root, root->val });

        int result = 0;

        while (!s.empty()) {
            auto [node, max] = s.top();
            s.pop();

            if (!node) continue;

            result += (node->val >= max);

            s.push(std::pair{ node->left,
                std::max(max, node->val) });
            s.push(std::pair{ node->right,
                std::max(max, node->val) });
        }

        return result;
    }
};