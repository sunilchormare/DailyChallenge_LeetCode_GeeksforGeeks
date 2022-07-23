class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int count=0,n=intervals.length,left=0,right=1;
        Arrays.sort(intervals,(a,b) -> a[1]-b[1]);
        for(int []i :intervals)
        {
            System.out.println("{a,b} "+" { "+i[0]+","+i[1]+" } ");
        }
        while(right<n)
        {
            if(intervals[left][1]<=intervals[right][0])
            {
                left=right;
                right++;
            }
            else if(intervals[left][1]<=intervals[right][1])
            {
                count++;
                right++;
            }
            else if(intervals[left][1]>intervals[right][1])
            {
                count++;
                left=right;
                right++;
            }
            
        }
        
        return count;
    }
}