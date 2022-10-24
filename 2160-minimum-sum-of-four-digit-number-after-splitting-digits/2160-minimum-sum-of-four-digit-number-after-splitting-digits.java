class Solution {
    public int minimumSum(int num) {
        int digit[]=new int[4];
        for(int x=0; x < 4; x++) {
            digit[x] = num%10;
            num = num/10;
        }
        Arrays.sort(digit);
        int f = digit[0] * 10 + digit[2];
        int s = digit[1] * 10 + digit[3];
        
        return f + s;
    }
}