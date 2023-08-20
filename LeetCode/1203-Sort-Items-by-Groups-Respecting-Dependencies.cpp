class Solution {
public:
    vector<int> groupVisited, itemVisited, res; 
    vector<vector<int>> groupMember, groupGraph, interGroupGraph;
    
    bool dfsItem(int item) {
        if(itemVisited[item]==1) return false;
        if(itemVisited[item]==2) return true;
        itemVisited[item]=1;

        for(auto pre: interGroupGraph[item])
            if(!dfsItem(pre))
                return false;

        res.push_back(item);
        itemVisited[item] = 2;
        return true;
    }

    bool dfsGroup(int group) {
        if(groupVisited[group]==1) return false;
        if(groupVisited[group]==2) return true;
        groupVisited[group]=1;

        for(auto pre: groupGraph[group])
            if(!dfsGroup(pre)) return false;

        for(auto item: groupMember[group])
            if(!dfsItem(item)) return false;

        groupVisited[group]=2;
        return true;
    }

    vector<int> sortItems(int items, int groups, vector<int>& group, vector<vector<int>>& beforeItems) {
        groupMember=vector<vector<int>>(groups);

        for(int item=0; item<items; ++item) {
            if(group[item]==-1) {
                group[item]=groups++;
                groupMember.push_back(vector<int>());
            }
            groupMember[group[item]].push_back(item);
        }

        groupGraph=vector<vector<int>>(groups);
        interGroupGraph=vector<vector<int>>(items);

        for(int item=0; item<items; ++item) {
            int groupNo=group[item];

            for(auto pre: beforeItems[item]) {
                int preGroupNo=group[pre];

                if(groupNo!=preGroupNo)
                    groupGraph[groupNo].push_back(preGroupNo);
                else
                    interGroupGraph[item].push_back(pre); 
            }
        }

        groupVisited=vector<int>(groups);
        itemVisited=vector<int>(items);
        res.reserve(items);

        for(int i=0; i<groups; ++i)
            if(!dfsGroup(i)) return vector<int>();

        return res;
    }
};