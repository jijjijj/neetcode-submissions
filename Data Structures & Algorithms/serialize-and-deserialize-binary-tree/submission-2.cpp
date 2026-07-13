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
#include <ranges>
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::stringstream ss;

        ser(root, ss);

        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::istringstream ss{ data };

        return des(ss);
    }

private:
    void ser(TreeNode* node, std::stringstream& ss) const {
        ss << (node ? std::to_string(node->val) : std::string{ "N" }) << "\n";

        if (node) {
            ser(node->left, ss);
            ser(node->right, ss);
        }
    }

    TreeNode* des(std::istringstream& ss) const {
        std::string val;
        ss >> val;

        if (val != "N") {
            TreeNode* node = new TreeNode{ std::stoi(val) };

            node->left = des(ss);
            node->right = des(ss);

            return node;
        }

        return nullptr;
    }
};
