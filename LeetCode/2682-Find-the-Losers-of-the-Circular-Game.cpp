class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        set<int> recv;
        int curr=0, i=1;
        while(!recv.count(curr)) {
            recv.insert(curr);
            curr=(curr+(i*k))%n;
            ++i;
        }

        vector<int> ans;
        for(int i=0; i<n; ++i) {
            if(!recv.count(i))
                ans.push_back(i+1);
        }
        return ans;
    }
};