class Solution {
public:
   int minimumOperations(vector<int>& nums) {
    vector<int> freq(101, 0);
    for(int i = nums.size()-1; i >= 0; --i){
        if(++freq[nums[i]] > 1) return ceil((double)(i + 1)/3);
    }
    return 0;
}
};