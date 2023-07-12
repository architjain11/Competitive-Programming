class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i, unordered_map<int, bool>& safe) {
        if(safe.count(i)) return safe[i];
        safe[i]=false;
        for(auto neighbour: graph[i])
            if(!dfs(graph, neighbour, safe))
                return safe[i];
        safe[i]=true;
        return safe[i];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        unordered_map<int, bool> safe;
        for(int i=0; i<graph.size(); ++i)
            if(dfs(graph, i, safe)) ans.push_back(i);
        return ans;
    }
};