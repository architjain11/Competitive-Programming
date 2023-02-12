class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        stack<int> s1, s2, tmp;
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++) {
            int num=nums[i];
            while(!s1.empty() && num>nums[s1.top()]) {
                tmp.push(s1.top());
                s1.pop();
            }
            while(!s2.empty() && num>nums[s2.top()]) {
                ans[s2.top()]=num;
                s2.pop();
            }
            while(!tmp.empty()) {
                s2.push(tmp.top());
                tmp.pop();
            }
            s1.push(i);
        }
        return ans;
    }
};