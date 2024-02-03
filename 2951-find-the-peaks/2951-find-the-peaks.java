class Solution {
    public List<Integer> findPeaks(int[] m) {
         List<Integer> ans=new ArrayList<>();
        
        for(int i=1;i<m.length-1;++i)
        {
            if(m[i]>m[i-1]&&m[i]>m[i+1])
                ans.add(i);
            
        }
        
        
        return ans;
    }
}