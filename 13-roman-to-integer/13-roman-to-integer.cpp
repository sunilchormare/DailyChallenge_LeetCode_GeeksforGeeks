class Solution {
    public int romanToInt(String s) {
          int currHighest = 0;
        int ans = 0;
        
        Map<Character, Integer> mp=new HashMap<>();
        mp.put('I',1);
        mp.put('V',5);
        mp.put('X',10);
        mp.put('L',50);
        mp.put('C',100);
        mp.put('D',500);
        mp.put('M',1000);
        
        int n = s.length();
        for(int i=n-1; i>=0; i--) 
        {
            if(mp.get(s.charAt(i)) < currHighest) 
            {
                ans -= mp.get(s.charAt(i));
            } 
            else 
            {
                currHighest = mp.get(s.charAt(i));
                ans += currHighest;
            }
        }
        return ans;
    }
}