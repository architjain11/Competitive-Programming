class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        string tmp="";
        int curr;
        for(auto x: nums) {
            if(tmp=="") {
                tmp+=to_string(x);
                curr=x;
            }
            else if(x==curr+1) {
                curr=x;
            }
            else {
                if(curr!=stoi(tmp)) 
                    tmp+="->"+to_string(curr);
                ranges.push_back(tmp);
                tmp=""+to_string(x);
                curr=x;
            }
        }
        cout<<curr<<tmp[0]-'0';

        if(tmp!="") {
            if(curr!=stoi(tmp)) 
                tmp+="->"+to_string(curr);
            ranges.push_back(tmp);
        }

        return ranges;
    }
};