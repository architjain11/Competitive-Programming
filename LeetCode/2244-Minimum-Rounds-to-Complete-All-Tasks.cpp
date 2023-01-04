class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for(auto task: tasks) m[task]++;
        int rounds=0;
        for(auto it: m) {
            int freq=it.second;
            if(freq==1) return -1;
            if(freq%3==0) rounds+=freq/3;
            else rounds+=freq/3+1;
        }
        return rounds;
    }
};