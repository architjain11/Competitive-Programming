class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, max=0;
        while(l<r) {
            int volume = min(height[l], height[r]) * (r-l);
            max = volume>max?volume:max;
            if(height[l]>height[r]) r--;
            else l++;
        }
        return max;
    }
};