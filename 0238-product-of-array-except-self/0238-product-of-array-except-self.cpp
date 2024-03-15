class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
    vector<int> products(n);
        products[0] = 1;
        for (int i = 1; i < n; i++) {
            products[i] = products[i - 1] * nums[i - 1];
        }
        int base = 1;
        for (int i = n - 2; i >= 0; i--) {
            base = base * nums[i + 1];
            products[i] = products[i] * base;
        }
        return products;
    }
};