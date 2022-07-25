class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        //if(nums.empty())return {};
        List<Integer> ans=new ArrayList<>();
        for(int i=0;i<nums.length;i++)
        {
            if(nums[Math.abs(nums[i])-1]<0)
                ans.add(Math.abs(nums[i]));
            nums[Math.abs(nums[i])-1]=-nums[Math.abs(nums[i])-1];
        }
        return ans;
    }
}

//  List<Integer> res = new ArrayList<>();
//         for (int i = 0; i < nums.length; ++i) {
//             int index = Math.abs(nums[i])-1;
//             if (nums[index] < 0)
//                 res.add(Math.abs(index+1));
//             nums[index] = -nums[index];
//         }
//         return res;