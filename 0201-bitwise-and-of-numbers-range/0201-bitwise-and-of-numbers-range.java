class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        // if(m == 0){
        //     return 0;
        // }
        // int moveFactor = 1;
        // while(m != n){
        //     m >>= 1;
        //     n >>= 1;
        //     moveFactor <<= 1;
        // }
        // return m * moveFactor;
        
        int res = right;
        while(right > left) {
            res = right & (right-1);
            right = res;
        }
        return res;
    }
}