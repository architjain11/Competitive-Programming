class Solution {
public:
    int climbStairs(int n) {
        vector<int> a;
        a.push_back(0);
        a.push_back(1);
        a.push_back(2);
        for(int i=3; i<n+1; i++) {
            a.push_back(a[i-1]+a[i-2]);
        }
        
        return a[n];
    }
};