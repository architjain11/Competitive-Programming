class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(), ans=0;
        unordered_map<int, int> m; //type->freq
        for(int i=0; i<n; i++) {
            if(m[fruits[i]]!=0 || m.size()<=2) {
                m[fruits[i]]++;
            }
            else {
                int count=0;
                for(auto [type, freq]: m) count+=freq;
                ans=max(ans, count);

                int prev=fruits[i-1];
                count=0;
                for(int j=i-1; j>=0; j--)
                    if(fruits[j]==prev) count++;
                    else break;
                m.clear();
                m[prev]=count;
                m[fruits[i]]++;
            }
        }
        int count=0;
        for(auto [type, freq]: m) count+=freq;
        ans=max(ans, count);
        return ans;
    }
};