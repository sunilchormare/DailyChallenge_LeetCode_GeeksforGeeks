class Solution {
    public int sumOfUnique(int[] nums) {
       int cnt[]=new int[101]; 
        int res = 0;
    for (int n : nums)
        ++cnt[n];
    for (int i = 1; i <= 100; ++i)
        if (cnt[i] == 1)
            res += i;
    return res;  
    }
}