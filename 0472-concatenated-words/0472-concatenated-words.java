class Solution {
    
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> result=new ArrayList<>();
       Set<String> dict=new HashSet<>();
        int min=Integer.MAX_VALUE;
        
        for(String word:words)
        {
             if(word.length()==0) continue;
             dict.add(word);
            min=Math.min(min,word.length());
            
        }
        for(String word:words)
        {
            if(canForm(word,dict,min))
            {
                result.add(word);
            }
        }
        return result;
    }
    
    boolean canForm(String word,Set<String> dict,int min)
    {
        
        for(int i=min;i<=word.length();++i)
        {
        String left=word.substring(0,i);
        String right=word.substring(i);
            if(dict.contains(left))
            {
                if(dict.contains(right)||canForm(right,dict,min))
                {
                    return true;
                }
            }
        }
      
      return false;  
    }
}