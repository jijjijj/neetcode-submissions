class Solution {
public:
    // dijkstra
    // bellmann-ford
    // SPFA
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<std::pair<int, int>>> e(n);

        for (const auto& f : flights) {
            e[f[0]].emplace_back(std::pair{ f[1], f[2] });
        }

        const int cInf = std::numeric_limits<int>::max();
        std::vector<int> prices(n, cInf);
        prices[src] = 0;

        for (int i = 0; i <= k; ++i) {
            std::vector<int> tmp = prices;

            for (const auto& flight : flights) {
                const int a = flight[0];
                const int b = flight[1];
                const int w = flight[2];

                if (prices[a] == cInf) continue;

                if (prices[a] + w < tmp[b]) {
                    tmp[b] = prices[a] + w;
                }
            }

            prices = std::move(tmp);
        }

        return prices[dst] == cInf ? -1 : prices[dst];
    }
};
