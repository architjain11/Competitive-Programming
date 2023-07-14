class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> maxLen;
        for(int i=0; i<arr.size(); ++i)
            maxLen[arr[i]]=maxLen[arr[i]-difference]+1;
        
        auto it=max_element(maxLen.begin(), maxLen.end(), [](const auto& x, const auto& y) {
            return x.second<y.second;
        });
        return it->second;
    }
};