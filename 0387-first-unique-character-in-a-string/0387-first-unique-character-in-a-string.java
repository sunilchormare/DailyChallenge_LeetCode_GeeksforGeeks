class Solution {
    public int firstUniqChar(String s) {
         if(s.length()==1) return 0;
        Map<Character,Integer> mp=new HashMap<>();
        for(int i=0;i<s.length();++i)
            mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0)+1);
        for(int i=0;i<s.length();++i)
            if(mp.get(s.charAt(i))==1)
                return i; 
          return -1;  
    }
}