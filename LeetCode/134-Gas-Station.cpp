class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_gas=0, total=0, start=0;
        for(int i=0; i<gas.size(); i++) {
            int net=gas[i]-cost[i];
            total+=net;
            curr_gas+=net;
            if(curr_gas<0) {
                curr_gas=0;
                start=i+1;
            }
        }
        return total<0?-1:start;
    }
};