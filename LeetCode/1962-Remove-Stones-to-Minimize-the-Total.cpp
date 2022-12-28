class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(auto x: piles) q.push(x);
        while(k--) {
            int tmp=q.top();
            q.pop();
            tmp-=tmp/2;
            q.push(tmp);
        }
        int ans=0;
        while(!q.empty()) {
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};