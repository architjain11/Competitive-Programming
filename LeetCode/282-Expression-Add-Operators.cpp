class Solution {
public:
    void nextOp(vector<string>& ans, long curr_val, int &target, string curr_expr, string num, long prevNum, long multed) {
        if(curr_val==target && !num.size()) {
            ans.push_back(curr_expr);
            return;
        }
        
        for(int i=1; i<=num.size(); ++i) {
            string curr=num.substr(0, i);
            if(curr.size()>1 && curr[0]=='0') return;

            long currNum=stol(curr);
            string next=num.substr(i);
            if(curr_expr.size()>0) {
                nextOp(ans, curr_val-multed+multed*currNum, target, curr_expr+'*'+curr, next, prevNum*currNum, multed*currNum);
                nextOp(ans, curr_val-currNum, target, curr_expr+'-'+curr, next, -currNum, -currNum);
                nextOp(ans, curr_val+currNum, target, curr_expr+'+'+curr, next, currNum, currNum);
            }
            else
                nextOp(ans, currNum, target, curr, next, currNum, currNum);
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        nextOp(ans, 0, target, "", num, 0, 0);
        return ans;
    }
};