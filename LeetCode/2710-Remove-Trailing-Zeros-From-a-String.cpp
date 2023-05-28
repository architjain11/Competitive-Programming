class Solution {
public:
    string removeTrailingZeros(string num) {
        int i=num.length()-1, j=0;
        while(i>=0 && num[i--]=='0')
            j++;
        
        return num.substr(0, num.length()-j);
    }
};