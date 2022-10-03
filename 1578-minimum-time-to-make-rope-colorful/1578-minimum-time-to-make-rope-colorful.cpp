class Solution {
    public int minCost(String colors, int[] neededTime) {
        int cost=0,curMax=0;
        for(int i=0;i<colors.length();++i)
        {
            if(i>0&&colors.charAt(i)!=colors.charAt(i-1))
                curMax=0;
            cost+=Math.min(curMax,neededTime[i]);
            curMax=Math.max(curMax,neededTime[i]);
        }
        return cost;
    }
}