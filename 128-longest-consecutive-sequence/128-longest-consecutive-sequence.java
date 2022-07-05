class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     
//   sort(nums.begin(),nums.end());
        
//         int longestStreak=0;
//         for(int i=1;i<nums.size();++i)
//         {
//             if(nums[i]+1==nums[i-1])
//             {
//                 currentStreak++; 
//             }
//             else
//             {
                
//             }
            
//             longestStreak=max(longestStreak,currentStreak);
//         }
        
        
//         return longestStreak;
//     }
        
        set<int> num_set;
        for (int num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (int num : num_set) {
            if (!num_set.count(num-1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum+1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak =max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};