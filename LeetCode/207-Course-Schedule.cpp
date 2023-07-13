class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> depend(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& prereq: prerequisites) {
            int x=prereq[0], y=prereq[1];
            depend[y].push_back(x);
            indegree[x]++;
        }

        queue<int> q;
        for(int course=0; course<numCourses; ++course)
            if(indegree[course]==0) q.push(course);
        while(!q.empty()) {
            int course=q.front(); q.pop();
            for(auto next: depend[course]) {
                indegree[next]--;
                if(indegree[next]==0) q.push(next);
            }
        }

        for(auto indeg: indegree)
            if(indeg)
                return false;
        return true;
    }
};