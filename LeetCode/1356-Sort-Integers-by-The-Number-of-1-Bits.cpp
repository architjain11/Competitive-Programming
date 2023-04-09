class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, multiset<int>> m;
        for(auto num: arr) {
            int count=0, cpy=num;
            while(cpy) {
                cpy=cpy&(cpy-1);
                count++;
            }
            m[count].insert(num);
        }

        vector<int> ans;
        for(auto [key, values]: m) {
            for(auto val: values) ans.push_back(val);
        }

        return ans;
    }
};