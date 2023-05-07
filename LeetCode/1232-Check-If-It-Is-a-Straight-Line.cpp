class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1=coordinates[0][0], y1=coordinates[0][1], x2=coordinates[1][0], y2=coordinates[1][1];
        if(x1==x2) {
            int same=coordinates[0][0];
            for(auto x: coordinates)
                if(x[0]==same) continue;
                else return false;
            return true;
        }

        float m=(float)(y2-y1)/(x2-x1), c=y1-(m*x1);
        cout<<m<<" "<<c;

        for(int i=2; i<coordinates.size(); ++i) {
            int x=coordinates[i][0], y=coordinates[i][1];
            if(y==m*x+c) continue;
            return false;
        }
        return true;
    }
};