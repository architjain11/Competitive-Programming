class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        HashSet<Integer> s = new HashSet<>();
        List<Integer> duplicates = new ArrayList<>();

        for(var num: nums) {
            if(s.contains(num)) duplicates.add(num);
            else s.add(num);
        }

        return duplicates;
    }
}