class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> a;
        int len=s.length(), max=0;
        for(int i=0; i<len; i++) {
            a.insert(s[i]);
            int length=1;
            
            for(int j=i+1; j<len; j++) {
                if(a.count(s[j])) {
                    break;
                }
                else {
                    a.insert(s[j]);
                    length++;
                }
            }
            
            max = max<length?length:max;
            a.clear();
        }
        return max;
    }
};