// class Solution {
// public:
// //     int majorityElement(vector<int>& nums) {
// //         // sort(nums.begin(), nums.end());
// //         // return nums[nums.size()/2];
// //         int major=num[0], count = 1;
// //         for(int i=1; i<num.length;i++){
// //             if(count==0){
// //                 count++;
// //                 major=num[i];
// //             }else if(major==num[i]){
// //                 count++;
// //             }else count--;
            
// //         }
// //         return major;
// //     }
    
//     int major=num[0], count = 1;
//         for(int i=1; i<num.length;i++){
//             if(count==0){
//                 count++;
//                 major=num[i];
//             }else if(major==num[i]){
//                 count++;
//             }else count--;
            
//         }
//         return major;
// }

public class Solution {
    public int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
}