class Solution {
    public long countBadPairs(int[] nums) {
         long pair = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            int diff = nums[i] - i;
            pair += i - map.getOrDefault(diff, 0);
            map.put(diff, map.getOrDefault(diff, 0) + 1);
        }
        return pair;
    }
}