class Solution {
public:
    int solve(int i, vector<int>& cookies, vector<int>& distribute, int k, int zeroCount) {
        if(cookies.size()-i<zeroCount)
            return INT_MAX;

        if(i==cookies.size())
            return *max_element(distribute.begin(), distribute.end());
        
        int answer=INT_MAX;
        for(int j=0; j<k; ++j) {
            zeroCount-=distribute[j]==0?1:0;
            distribute[j]+=cookies[i];

            answer=min(answer, solve(i+1, cookies, distribute, k, zeroCount));
            distribute[j]-=cookies[i];
            zeroCount+=distribute[j]==0?1:0;
        }
        return answer;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribute(k, 0);
        return solve(0, cookies, distribute, k, k);
    }
};