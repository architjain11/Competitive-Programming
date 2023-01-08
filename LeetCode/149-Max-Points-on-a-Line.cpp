class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxpoints=0;
        for(int i=0; i<points.size()-maxpoints; i++) {
            int local_max=INT_MIN;
            unordered_map<float, int> m;

            for(int j=i+1; j<points.size(); j++) {
                int x1=points[i][0], y1=points[i][1], x2=points[j][0], y2=points[j][1];
                float slope;
                if(x2-x1==0) slope=INT_MAX;
                else slope=(float)(y2-y1)/(float)(x2-x1);
                m[slope]++;
                local_max=max(local_max, m[slope]);
            }
            maxpoints=max(maxpoints, local_max);
        }
        return maxpoints+1;
    }
};