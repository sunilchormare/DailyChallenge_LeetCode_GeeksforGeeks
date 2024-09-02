class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long sum=0;
        for(int i=0;i<chalk.length;i++) sum+=chalk[i];
        int left=(int)(k%sum);
        for(int i=0;i<chalk.length;i++) {
            if(left<chalk[i]) return i;
            left-=chalk[i];
        }
        return 0;
    }
}