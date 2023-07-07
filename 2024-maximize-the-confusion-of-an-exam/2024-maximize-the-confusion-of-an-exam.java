class Solution {
  public int maxConsecutiveAnswers(String s, int k) 
  {  return Math.max(solve(s,'F',k),solve(s,'T',k));  
  }
    
   int solve(String s,char b,int k){
       int left=0,res=0,size=s.length(),count=0;
      for(int i=0;i<size;i++)
      {
            if(s.charAt(i)==b)
                count++;
            if(count>k)
            {
                if(s.charAt(left)==b)
                    count--;
                left++;
            }
            
          res=Math.max(i-left+1,res);
        
      }
        return res;
    }
}