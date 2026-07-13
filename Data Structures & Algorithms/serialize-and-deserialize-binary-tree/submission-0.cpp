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
        std::queue<std::pair<TreeNode*,TreeNode*>> q; // node
        std::unordered_map<TreeNode*, int> ids; // node -> id

        size_t id = 0;

        q.push(std::pair{ root, nullptr });

        std::vector<int> arr;

        while (!q.empty()) {
            for (size_t i = q.size(); i > 0; --i) {
                auto [node, parent] = q.front();
                q.pop();

                if (node) {
                    ids[node] = ++id;

                    arr.emplace_back(ids[parent]);
                    arr.emplace_back(node->val);
                    arr.emplace_back(id);
                    arr.emplace_back((parent && parent->left == node) ? 1 : 0);

                    q.push(std::pair{ node->left, node });
                    q.push(std::pair{ node->right, node });
                }
            }
        }

        std::string result = arr
            | std::views::transform([](int v) { return std::to_string(v); })
            | std::views::join_with(std::string(" "))
            | std::ranges::to<std::string>();
        
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<int> arr;

        std::unordered_map<int, TreeNode*> id;

        TreeNode* root = nullptr;

        for (const auto& word : std::views::split( data, ' ' )) {
            arr.emplace_back(std::stoi(std::string{ std::string_view{ word } }));
        }

        for (size_t i = 0; i < arr.size(); i += 4) {
            int parent_id = arr[i];
            int val = arr[i + 1];
            int node_id = arr[i + 2];
            int is_left = arr[i + 3];

            TreeNode* node = new TreeNode{ val };
            id[node_id] = node;

            if (parent_id) {
                (is_left ? id[parent_id]->left : id[parent_id]->right) =
                    node;
            } else {
                root = node;
            }
        }

        return root;
    }
};
