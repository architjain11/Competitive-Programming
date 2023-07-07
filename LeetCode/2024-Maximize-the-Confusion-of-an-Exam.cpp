class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0, count=0, j=0;
        for(int i=0; i<answerKey.size(); ++i) {
            if(answerKey[i]=='T') count++;
            while(count>k) {
                if(answerKey[j]=='T') count--;
                j++;
            }
            ans=max(ans, i-j+1);
        }
        count=0; j=0;
        for(int i=0; i<answerKey.size(); ++i) {
            if(answerKey[i]=='F') count++;
            while(count>k) {
                if(answerKey[j]=='F') count--;
                j++;
            }
            ans=max(ans, i-j+1);
        }

        return ans;
    }
};