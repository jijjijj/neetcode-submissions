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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string res;

        std::stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            auto node = s.top();
            s.pop();

            if (node) {
                res += "," + std::to_string(node->val);
                s.push(node->right);
                s.push(node->left);
            }
            else res += ",null";
        }
        // std::cout << res;
        return res.substr(1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode fake;
        
        std::stack<std::pair<TreeNode*, bool>> s;
        s.push({ &fake, false });

        std::stringstream ss{ data };
        std::string part;
        while (std::getline(ss, part, ',')) {
            // std::cout << part << std::endl;
            auto [node, v] = s.top();
            s.pop();

            // std::cout << node->val << " " << v << std::endl;

            if (!v) {
                s.push({ node, true });

                if (part == "null") {
                    node->left = nullptr;
                } else {
                    node->left = new TreeNode{
                        std::stoi(part) };

                    s.push({ node->left, false });
                }
            } else {
                if (part == "null") {
                    node->right = nullptr;
                } else {
                    node->right = new TreeNode{
                        std::stoi(part) };

                    s.push({ node->right, false });
                }
            }
        }

        return fake.left;
    }
};
