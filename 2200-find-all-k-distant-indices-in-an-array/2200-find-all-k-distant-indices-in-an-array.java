class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
     List<Integer> res=new ArrayList<>();
    for (int i = 0, j = 0; i < nums.length; ++i)
        if (nums[i] == key)
            for (j = Math.max(j, i - k); j <= i + k && j < nums.length; ++j)
                res.add(j);
    return res;   
    }
}