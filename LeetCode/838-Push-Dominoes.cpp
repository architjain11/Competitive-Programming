class Solution {
public:
    string pushDominoes(string dominoes) {
        int pointer=0;
        int n=dominoes.length();
        for(int i=0; i<n; i++) {
            if(dominoes[i]=='.') continue;
            if(dominoes[i]=='L') {
                for(int j=pointer; j<=i; j++) {
                    dominoes[j]='L';
                }
                pointer=i+1;
                continue;
            }
            if(dominoes[i]=='R') {
                pointer=i+1;
                while(dominoes[i]!='L' && i!=n) {
                    i++;
                    if(dominoes[i]=='R') {
                        for(int j=pointer; j<i; j++) dominoes[j]='R';
                        pointer=i+1;
                    }
                }
                if(i==n) {
                    for(int j=pointer; j<i; j++) dominoes[j]='R';
                }
                else {
                    int left=pointer, right=i-1;
                    pointer=i+1;
                    while(left!=right && left<right) {
                        dominoes[left]='R';
                        dominoes[right]='L';
                        left++; right--;
                    }
                }
            }
        }
        return dominoes;
    }
};