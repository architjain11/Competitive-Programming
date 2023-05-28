class Solution {
public:
    map<pair<int, int>, int> cache;

    int cost(int l, int r, vector<int>& cuts) {
        if(r-l==1) return 0;
        if(cache[{l, r}]) return cache[{l, r}];

        int res=INT_MAX;
        for(auto cut: cuts)
            if(cut<r && cut>l)
                res=min(res, r-l+cost(l, cut, cuts)+cost(cut, r, cuts));

        res=(res==INT_MAX?0:res);
        cache[{l, r}]=res;
        
        return res;
    }

    int minCost(int n, vector<int>& cuts) {
        return cost(0, n, cuts);
    }
};