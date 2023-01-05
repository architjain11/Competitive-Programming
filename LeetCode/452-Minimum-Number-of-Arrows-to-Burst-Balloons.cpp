class Solution {
public:
    bool static sorted(vector<int>& a, vector<int>& b) {
        return a[1]<b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), sorted);
        int arrows=1, end=points[0][1];
        for(int i=1; i<points.size(); i++) {
            if(points[i][0]>end) {
                end=points[i][1];
                arrows++;
            }
        }
        return arrows;
    }
};