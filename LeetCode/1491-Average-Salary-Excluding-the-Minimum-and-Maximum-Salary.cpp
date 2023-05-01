class Solution {
public:
    double average(vector<int>& salary) {
        double n=salary.size(),
            sum=accumulate(salary.begin(), salary.end(), 0),
            maxi=*max_element(salary.begin(), salary.end()),
            mini=*min_element(salary.begin(), salary.end());

        return (sum-maxi-mini)/(n-2);
    }
};