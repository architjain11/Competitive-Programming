class Solution {
public:
    int bestClosingTime(string customers) {
        int current=count(customers.begin(), customers.end(), 'Y');
        int minPenalty=current;
        int ans=0;

        for(int i=0; i<customers.size(); ++i) {
            char c=customers[i];
            if(c=='Y') current--;
            else current++;

            if(current<minPenalty) {
                ans=i+1;
                minPenalty=current;
            }
        }
        return ans;
    }
};