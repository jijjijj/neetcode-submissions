class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int sum = std::accumulate(piles.begin(), piles.end(), 0);

        return f(piles, 0, piles.size() - 1, 1) > (sum / 2);
    }

private:
    int f(vector<int>& piles, int i, int j, int alice) {
        if (i > j) return 0;

        return std::max(f(piles, i + 1, j, !alice) + (alice ? piles[i] : 0),
            f(piles, i, j - 1, !alice) + (alice ? piles[j] : 0));
    }
};