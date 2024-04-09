class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int t=0;
        if(tickets[k]==1) return k+1;

        while(tickets[k]>0) {
            for(int i=0; i<tickets.length; ++i) {
                if(tickets[i]!=0) {
                    tickets[i]--;
                    t++;
                }
                if(tickets[k]==0)
                    return t;
            }
        }

        return t;
    }
}