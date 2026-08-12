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
        std::stringstream res;
        res << "n";

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();

                if (node) {
                    res << " " << std::to_string(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
                else res << " n";
            }
        }
        
        return res.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode fake;
        
        // std::cout << data;

        std::stringstream ss{ data };
        std::string part;

        std::queue<TreeNode*> q;
        q.push(&fake);
        // std::cout << std::endl;
        while (std::getline(ss, part, ' ')) {
            // std::cout << part << std::endl;
            // return nullptr;
            // for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();

                // std::cout << "processing " << node->val << ": ";

                node->left = (part == "n" ? nullptr : new TreeNode{ std::stoi(part) });
                
                // std::cout << part << " ";
                std::getline(ss, part, ' ');
            // std::cout << part << std::endl;
                // std::cout << part << "\n";

                node->right = (part == "n" ? nullptr : new TreeNode{ std::stoi(part) });

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            // }
            // std::cout << std::endl;
        }

        return fake.right;
    }
};
