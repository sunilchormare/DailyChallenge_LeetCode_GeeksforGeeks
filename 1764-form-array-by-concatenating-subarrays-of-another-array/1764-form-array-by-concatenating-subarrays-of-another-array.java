class Solution {
    public boolean canChoose(int[][] groups, int[] nums) {
         int idx=0;
        for(int i=0;i<nums.length&&idx<groups.length;i++) {
            if(i+groups[idx].length-1<nums.length) {
                int j=0;
                for(j=0;j<groups[idx].length;j++) {
                    if(groups[idx][j]!=nums[i+j]) break;
                }
                if(j==groups[idx].length) {
                    i+=groups[idx].length-1;
                    idx++;
                }
            }
        }
        return idx>=groups.length;
    }
}