class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size()==0) return 1;
        unordered_set<int> s;
        unordered_map<int, int> m;
        for(auto x: trust) {
            m[x[1]]++;
            s.insert(x[0]);
        }
        for(auto [person, trustedby]: m)
            if(trustedby==n-1 && !s.count(person)) return person;

        return -1;
    }
};