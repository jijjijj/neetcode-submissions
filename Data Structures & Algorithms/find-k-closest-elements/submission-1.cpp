class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // arr[i] -> std::abs(arr[i] - x)

        int best_l = 0;
        int best_r = 0;
        int best_max = std::numeric_limits<int>::max();

        int dist = 0;
        int l = 0;

        // std::priority_queue<std::pair<int, int>> q;  // val, i
        for (int r = 0; r < arr.size(); ++r) {
            // q.push({ std::abs(arr[r] - x), r });

            // while (!q.empty() && q.top().second < r - k + 1) {
            //     q.pop();
            // }
            dist += std::abs(arr[r] - x);

            if (r >= k - 1) {
                if (dist < best_max) {
                    best_max = dist;
                    best_l = l;
                    best_r = r;
                }

                dist -= std::abs(arr[l] - x);
                ++l;
            }
        }

        std::vector<int> res(best_r - best_l + 1);

        for (int i = best_l; i <= best_r; ++i)
            res[i - best_l] = arr[i];
        
        return res;
    }
};