class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int sum = 0, maxWindow = 0, window = 0;
        
        for (int i = 0; i < customers.length; ++i) {
            sum += grumpy[i] == 0 ? customers[i] : 0;
            window += grumpy[i] == 1 ? customers[i] : 0;
            if (i >= X) window -= grumpy[i - X] == 1 ? customers[i - X] : 0;
            maxWindow = Math.max(maxWindow, window);
        }
        return sum + maxWindow;
    }
}