class Solution {
    public int bestClosingTime(String customers) {
        int maxProfit = 0;
        int profit = 0;
        int hour = 0;

        for(int i=0; i<customers.length(); i++){
            profit = customers.charAt(i)=='Y' ? profit+1 : profit-1;
            if(profit>maxProfit){
                maxProfit = profit;
                hour = i+1;
            }
        }

        return hour;
    }
}