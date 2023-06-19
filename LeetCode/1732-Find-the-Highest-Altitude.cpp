class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitudes={0};
        for(auto x: gain)
            altitudes.push_back(*(altitudes.end()-1)+x);
        return *max_element(altitudes.begin(), altitudes.end());
    }
};