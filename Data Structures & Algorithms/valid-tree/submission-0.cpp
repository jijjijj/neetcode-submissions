class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        return n - edges.size() == 1;
    }
};
