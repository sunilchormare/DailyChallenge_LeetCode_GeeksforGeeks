class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int[] nums: nums1 ){
            map.put(nums[0], nums[1]);
        }
        for(int[] nums: nums2 ){
            map.put(nums[0], map.getOrDefault(nums[0],0) + nums[1]);
        }
        
        int[][] res = new int[map.size()][2];
        int i = 0;
        int slow = 0;
        
        while(!map.isEmpty()){
            if(map.containsKey(i)){
                res[slow][0] = i;
                res[slow][1] = map.get(i);
                map.remove(i);
                slow++;
            }
            i++;
        }
        return res;
    }
}