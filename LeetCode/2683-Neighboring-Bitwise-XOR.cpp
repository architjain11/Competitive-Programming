class Solution {
public:
    bool createOriginal(int start, vector<int>& derived) {
        int curr=start;
        for(int i=0; i<derived.size()-1; ++i) {
            curr=derived[i]^curr;
        }
        if((curr^start)==derived[derived.size()-1]) return true;
        return false;        
    }
    
    bool doesValidArrayExist(vector<int>& derived) {
        return createOriginal(1, derived) || createOriginal(0, derived);
    }
};