class Solution {
    public int findFinalValue(int[] nums, int o) {
         int h[]=new int[1001];
        for(int i:nums) 
            h[i]++;
		
        while(o<=1000 && h[o]!=0)
            o*=2;
        
        return o;
    }
}