class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Queue<Integer> q = new LinkedList<>();
        int n = deck.length;

        for(int i=0; i<n; ++i) 
            q.add(i);

        Arrays.sort(deck);
        int[] ans = new int[n];
        
        for(int i=0; i<n; ++i) {
            ans[q.poll()] = deck[i];
            q.add(q.poll());
        }

        return ans;
    }
}