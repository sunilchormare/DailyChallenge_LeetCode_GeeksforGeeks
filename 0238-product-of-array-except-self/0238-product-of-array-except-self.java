class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] products = new int[nums.length];
        products[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            products[i] = products[i - 1] * nums[i - 1];
        }
        int base = 1;
        for (int i = nums.length - 2; i >= 0; i--) {
            base = base * nums[i + 1];
            products[i] = products[i] * base;
        }
        return products;
    }
}