class Solution {
     public int getMinSwaps(String num, int k) {
        char[] arr = num.toCharArray();
        for (int i = 0; i < k; i++) {
            nextPermutation(arr);
        }
        char[] ori = num.toCharArray();
        return CountSteps(ori, arr, arr.length);
    }
    
    public void nextPermutation(char[] nums) {
        if (nums.length == 0) return;
        int len = nums.length;
        for (int i = len - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                reverse(nums, i);
                for (int j = i; j < len; j++) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums, i - 1, j);
                        return;
                    }
                }
            }
        }
        reverse(nums, 0);
    }
    
    public void reverse(char[] nums, int i) {
        int j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    
    public void swap(char[] nums, int i, int j) {
        char temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp; 
    }
    
    private int CountSteps(char []s1, char[] s2, int size) {
        int i = 0, j = 0;
        int count = 0;

        while (i < size) {
            j = i;

            while (s1[j] != s2[i]) {
                j += 1;
            }
            while (i < j) {
                swap(s1, j, j - 1);
                j -= 1;
                count++;
            }
            i++;
        }
        return count;
    }
}