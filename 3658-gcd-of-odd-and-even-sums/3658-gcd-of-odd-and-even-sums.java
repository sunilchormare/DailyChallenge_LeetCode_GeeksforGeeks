class Solution {
    // public static int findGCD(int a, int b) {
    //     if (b == 0) {
    //         return a;
    //     }
    //     return findGCD(b, a % b);
    // }
    public static int findGCDIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

    public int gcdOfOddEvenSums(int n) {
        int sumOdd=0,sumEven=0,count=0,even=2,odd=1;
       while(count<n){

            sumEven+=even;
            sumOdd+=odd;
            even+=2;
            odd+=2;

            count++;
       }
        return findGCDIterative(sumOdd,sumEven);
    }
}