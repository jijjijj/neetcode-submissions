class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxi = 0;
        int max = -1;

        int cur = 0;
        for (int i = 0; i < gas.size(); ++i) {
            if (cur + gas[i] - cost[i] > max) {
                max = cur + gas[i] - cost[i];
                maxi = i;
            }

            cur += gas[i] - cost[i];
        }

        return max > -1 ? maxi : -1;
    }
};
