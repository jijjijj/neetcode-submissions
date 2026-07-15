class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxi = 0;
        int max = -1;

        int cur = 0;
        for (int i = 0; i < gas.size(); ++i) {
            if (gas[i] - cost[i] > max) {
                max = gas[i] - cost[i];
                maxi = i;
            }

            cur += gas[i] - cost[i];
        }

        return cur >= 0 ? maxi : -1;
    }
};
