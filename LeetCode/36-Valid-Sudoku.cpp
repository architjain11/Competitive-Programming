class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        for(auto row: board) {
            s.clear();
            for(auto ele: row) {
                if(ele != '.' && s.count(ele)) {
                    return false;
                }
                else {
                    s.insert(ele);
                }
            }
        }
        
        for(int i=0; i<board[0].size(); i++) {
            s.clear();
            for(auto row: board) {
                if(row[i]!='.' && s.count(row[i]))
                    return false;
                else
                    s.insert(row[i]);
            }
        }
        
        for (int iCount = 0; iCount < 9; iCount += 3) {
            for (int jCount = 0; jCount < 9; jCount += 3) {
                s.clear();
                for (int i = iCount; i < iCount + 3; i++) {
                    for (int j = jCount; j < jCount + 3; j++) {
                        if(board[i][j]!='.' && s.count(board[i][j]))
                            return false;
                        else
                            s.insert(board[i][j]);
                    }
                }
            }
        }
        
        return true;
        
    }
};