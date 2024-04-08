class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int circle=0, square=0;

        for(int s: students) {
            if(s==0) circle++;
            else square++;
        }

        for(int s: sandwiches) {
            if(s==0 && circle==0) return square;
            if(s==1 && square==0) return circle;

            if(
                s==0) circle--;
            else square--;
        }

        return 0;
    }
}