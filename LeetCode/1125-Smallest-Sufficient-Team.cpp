class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        unordered_map<int, vector<int>> dp;
        dp.reserve(1<<n);
        dp[0]={};

        unordered_map<string, int> skill_index;
        for(int i=0; i<n; ++i) skill_index[req_skills[i]]=i;

        for(int i=0; i<people.size(); ++i) {
            int currSkill=0;
            for(auto& skill: people[i])
                currSkill |= 1<<skill_index[skill];

            for(auto it=dp.begin(); it!=dp.end(); ++it) {
                int combination=it->first | currSkill;
                if(dp.find(combination)==dp.end() || dp[combination].size()>1+dp[it->first].size()) {
                    dp[combination]=it->second;
                    dp[combination].push_back(i);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};