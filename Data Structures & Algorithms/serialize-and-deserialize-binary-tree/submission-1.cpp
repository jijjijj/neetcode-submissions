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
        std::queue<TreeNode*> q;
        q.push(root);

        std::stringstream result;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                result << "N ";
            } else {
                result << std::to_string(node->val) << " ";

                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return result.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto range =
            std::views::split(data, std::string_view{ " " }) |
            std::views::filter([](const auto& r) { return !r.empty(); }) |
            std::views::transform([](const auto& r) {
                return std::string{ r.begin(), r.end() }; });
        auto it = range.begin();
        if (*it == "N") return nullptr;
        TreeNode* root = new TreeNode{ std::stoi(*it) };

        std::queue<TreeNode*> q;
        q.push(root);

        while (++it != range.end()) {
            TreeNode* node = q.front();
            q.pop();

            if (*it != "N") {
                node->left = new TreeNode{ std::stoi(*it) };
                q.push(node->left);
            }

            if (*(++it) != "N") {
                node->right = new TreeNode{ std::stoi(*it) };
                q.push(node->right);
            }
        }

        return root;
    }
};
