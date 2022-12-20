class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), 0);
        queue<int> keys;
        visited[0]=true;
        for(auto k: rooms[0]) keys.push(k);
        while(!keys.empty()) {
            int room=keys.front();
            keys.pop();
            if(visited[room]) continue;
            visited[room]=true;
            for(auto k: rooms[room]) keys.push(k);
        }
        for(auto x: visited) {
            if(x==false) return false;
        }
        return true;
    }
};