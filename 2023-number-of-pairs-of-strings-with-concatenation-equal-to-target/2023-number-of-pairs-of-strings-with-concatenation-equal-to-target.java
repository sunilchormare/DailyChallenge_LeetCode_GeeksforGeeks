class Solution {
    public int numOfPairs(String[] nums, String target) {
        Map<String, Integer> map = new HashMap<>();
        int tot = 0;
        for (int i = 0; i < nums.length; i++) {
            if (target.startsWith(nums[i])) {
                String sub = target.substring(nums[i].length());
                if (map.containsKey(sub))
                    tot += map.get(sub);
            }
           if (target.endsWith(nums[i])) {
                String sub = target.substring(0, target.length()-nums[i].length());
                if (map.containsKey(sub))
                    tot += map.get(sub);
            }
            map.put(nums[i], map.getOrDefault(nums[i], 0)+1);
        }
        return tot;
    }
}