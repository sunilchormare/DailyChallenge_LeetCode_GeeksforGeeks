class Solution {
    public int minBitFlips(int start, int goal) {
         int value = start^goal , count=0;
        while(value!=0)
        {
            value &=value-1;
            count++;
        }
        return count;
    }
}