class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int x=-1, y=-1, m=grid.size(), n=grid[0].size(), noOfKeys=-1;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                char cell=grid[i][j];
                if(cell=='@') {
                    x=i;
                    y=j;
                }
                if(cell>='a' && cell<='f')
                    noOfKeys=max(cell-'a'+1, noOfKeys);
            }
        }

        vector<int> start={0, x, y};
        queue<vector<int>> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(to_string(0)+" "+to_string(x)+" "+to_string(y));
        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int step=0;
        while(!q.empty()) {
            int size=q.size();
            for(int k=0; k<size; ++k) {
                vector<int> curr=q.front();
                q.pop();
                if(curr[0]==(1<<noOfKeys)-1) return step;
                for(auto& d: directions) {
                    int i=curr[1]+d[0],
                        j=curr[2]+d[1];
                    int keys=curr[0];

                    if(i>=0 && i<m && j>=0 &&j<n) {
                        char c=grid[i][j];
                        if(c=='#') continue;
                        if(c>='a' && c<='f')
                            keys|=1<<(c-'a');
                        if(c>='A' && c<='F' && ((keys>>(c-'A'))&1)==0)
                            continue;
                        if(!visited.count(to_string(keys)+" "+to_string(i)+" "+to_string(j))) {
                            visited.insert(to_string(keys)+" "+to_string(i)+" "+to_string(j));
                            q.push({keys, i, j});
                        }
                        

                    }
                }
            }
            ++step;
        }


        return -1;
    }
};