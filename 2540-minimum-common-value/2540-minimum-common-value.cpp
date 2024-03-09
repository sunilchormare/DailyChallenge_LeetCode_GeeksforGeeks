// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
// //         set<int> s;
// //         for(int a:nums1)
// //         {
// //             s.insert(a);
// //         }
        
// //         for(int i=0;i<nums2.size();++i)
// //         {
// //             if(s.count(nums2[i]))
// //             {
// //                 return nums2[i];
// //             }
// //         }
        
// //         return -1;
        
        
//     }
// };


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int first = 0;
        int second = 0;

        // Traverse through both arrays with two pointers
        // Increment the pointer with a smaller value at that index
        // Return the first common element found
        while (first < nums1.size() && second < nums2.size()) {
            if (nums1[first] < nums2[second]) {
                first++;
            } else if (nums1[first] > nums2[second]) {
                second++;
            } else {
                return nums1[first];
            }
        }

        // Return -1 if there are no common elements
        return -1;
    }
};