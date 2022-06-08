class Solution {
    public int removePalindromeSub(String s) {
        if(s.length()==0) 
            return 0;
      int st=0,end=s.length()-1;
        
      while(st<end)
      {
        if(s.charAt(st)==s.charAt(end))
        {
          st++;
          end--;
        }
        else
           return 2;
      }
        
      return 1;
    }
}