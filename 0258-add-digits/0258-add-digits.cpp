class Solution {
public:
    int addDigits(int num) {
//          int digitalRoot = 0;
//         while (num > 0) {
//             digitalRoot += num % 10;
//             num = num / 10;
            
//             if (num == 0 && digitalRoot > 9) {
//                 num = digitalRoot;
//                 digitalRoot = 0;  
//             }    
//         }     
//         return digitalRoot;
        
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};