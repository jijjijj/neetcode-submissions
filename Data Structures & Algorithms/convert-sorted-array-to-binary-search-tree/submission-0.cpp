class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(0, nums.size() - 1, nums);
    }

private:
    TreeNode* build(int l, int r,
        std::vector<int>& nums) {
        if (l > r) return nullptr;

        const int mid = l + (r - l) / 2;

        TreeNode* node = new TreeNode{ nums[mid] };
        node->left = build(l, mid - 1, nums);
        node->right = build(mid + 1, r, nums);

        return node;
    }
};
