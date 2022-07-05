class Solution {
    public int longestConsecutive(int[] nums) {
//         if (nums.length == 0) {
//             return 0;
//         }

//         Arrays.sort(nums);

//         int longestStreak = 1;
//         int currentStreak = 1;

//         for (int i = 1; i < nums.length; i++) {
//             if (nums[i] != nums[i-1]) {
//                 if (nums[i] == nums[i-1]+1) {
//                     currentStreak += 1;
//                 }
//                 else {
//                     longestStreak = Math.max(longestStreak, currentStreak);
//                     currentStreak = 1;
//                 }
//             }
//         }

//         return Math.max(longestStreak, currentStreak);
        
        //OPTIMIZED APPROACH
        
     Set<Integer> hashSet=new HashSet<Integer>();
     for(int num:nums) hashSet.add(num);
        int longestStreak=0;
        
      for(int num:nums)
      {
           if(!hashSet.contains(num-1))
           {
            int currentNum=num;
            int currentStreak=1;
            while(hashSet.contains(currentNum+1))
            {
                currentNum+=1;
                currentStreak++;
            }
               longestStreak=Math.max(longestStreak,currentStreak);
           }
      }
        
        return longestStreak;
    }
}














