class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int lastDay = 0;
       Set<Integer> set = new HashSet<>();
       for(int day : days){
           set.add(day);
           lastDay = Math.max(lastDay, day);
       }

       int[] dp = new int[lastDay+1];
       for(int day=1;day<=lastDay;day++){
           if(!set.contains(day)){
               dp[day] = dp[day-1];
               continue;
           }
           
           dp[day] = dp[day-1] + costs[0];
           dp[day] = Math.min(dp[day], costs[1] + dp[Math.max(0, day-7)]);
           dp[day] = Math.min(dp[day], costs[2] + dp[Math.max(0, day-30)]);
       }
       
       return dp[lastDay];
    }
}