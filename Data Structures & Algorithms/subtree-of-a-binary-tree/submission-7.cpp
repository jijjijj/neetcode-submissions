class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        const std::vector<int> rr = serialize(root);
        const std::vector<int> sr = serialize(subRoot);

        const auto ch = [&sr, &rr](int i) {
            if (i == sr.size()) return -102;
            return i < sr.size() ? sr[i] : rr[i - sr.size() - 1];
        };

        std::vector<int> z(sr.size() + rr.size() + 1, 0);

        int l = 0;
        int r = 0;
        
        for (int i = 0; i < z.size(); ++i) {
            if (i < r) {
                z[i] = std::min(z[i - l], r - i + 1);
            }

            while (i + z[i] < z.size() && ch(i + z[i]) == ch(z[i])) {
                ++z[i];
            }

            if (z[i] > r - l + 1) {
                l = i;
                r = i + z[i] - 1;
            }

            if (i > sr.size() && z[i] >= sr.size()) return true;

            // std::cout << "(" << z[i] << ", " << ch(i) << ") ";
        }

        return false;
    }

private:
    std::vector<int> serialize(TreeNode* root) {
        std::vector<int> res;

        std::stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            auto node = s.top();
            s.pop();

            res.emplace_back(node ? node->val : -101);

            if (node) {
                s.push(node->right);
                s.push(node->left);
            }
        }

        return res;
    }
};