// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//      //    set<int> mp;
//      //    for(int i=0; i<= sqrt(c); i++) {
//      //        mp.insert(i*i);
//      //        if(mp.find(c-i*i) !=mp.end()){
//      //            return true;
//      //        }
//      //    }
//      // return false;    
        
//         class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         set<int> mp;
//         for(int i=0; i<= sqrt(c); i++) {
//             mp.insert(i*i);
//             if(mp.find(c-i*i) !=mp.end()){
//                 return true;
//             }
//         }
//      return false;    
//     }
// };
//     }
// };


class Solution {
public:
    bool judgeSquareSum(int c) {
       if (c < 0) {
            return false;
        }
        long left = 0, right = (long)sqrt(c);
        while (left <= right) {
            long cur = left * left + right * right;
            if (cur < c) {
                left++;
            } else if (cur > c) {
                right--;
            } else {
                return true;
            }
        }
        return false;    
    }
};