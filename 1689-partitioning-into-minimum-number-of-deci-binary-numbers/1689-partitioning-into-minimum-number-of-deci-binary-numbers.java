class Solution {
    public int minPartitions(String n) {
         int maxi=0;
      for(char i:n.toCharArray())
          maxi=Math.max(maxi,i-'0');
      return maxi;
    }
}