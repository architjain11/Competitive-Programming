class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {
        int n=asteroid.size();
        stack<int> s;
        for(int i=0; i<n; ++i) {
            if(s.empty() || asteroid[i]>0) s.push(asteroid[i]);
            else {
                while(!s.empty() && s.top()>0 && s.top()<abs(asteroid[i]))
                    s.pop();
                if(!s.empty() && s.top()==abs(asteroid[i]))
                    s.pop();
                else if(s.empty() || s.top()<0)
                    s.push(asteroid[i]);
            }
        }
        int size=s.size();
        vector<int> ans(size);
        for(int i=size-1; i>=0; --i) {
            ans[i]=s.top();
            s.pop();
        }
        return ans;
    }
};