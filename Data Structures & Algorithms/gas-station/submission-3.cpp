class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int end = 0;
        int start = gas.size() - 1;
        int cur = gas[start] - cost[start];

        while (start > end) {
            if (cur < 0) {
                --start;
                cur += gas[start] - cost[start];
            } else {
                cur += gas[end] - cost[end];
                ++end;
            }
        }

        return cur >= 0 ? start : -1;
    }
};
