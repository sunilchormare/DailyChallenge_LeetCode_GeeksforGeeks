class Solution {
    public int findDuplicate(int[] nums) {
        int idx = 0;
        while (nums[idx] == idx) ++idx;
        while (nums[idx] != idx) {
            int tmp = idx;
            idx = nums[tmp];
            nums[tmp] = tmp;
        }
        return idx;
    }
}