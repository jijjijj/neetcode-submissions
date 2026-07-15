class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxi = 0;
        int max = std::numeric_limits<int>::max();

        int cur = 0;
        for (int i = 0; i < gas.size(); ++i) {
            if (cur < max) {
                maxi = i;
                max = cur;
            }
            
            cur += gas[i] - cost[i];
        }

        return cur >= 0 ? maxi : -1;
    }
};
