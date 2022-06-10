class Solution {
    public int lengthOfLongestSubstring(String s) {
//         HashMap<Character,Integer> mpp=new HashMap<Character,Integer>();
//         int right=0,left=0;
//         int n=s.length()-1;
//         int len=0;
//         if(n==0) return 1;
//         while(right<n)
//         {
//             if(mpp.containsKey(s.charAt(right)))
//                 left=Math.max(left,mpp.get(s.charAt(right))+1);
//             mpp.put(s.charAt(right),right);
//             len=Math.max(len,right-left+1);
//             right++;
//         }
        
//         return len;
        
         if (s.length()==0) return 0;
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int max=0;
        for (int i=0, j=0; i<s.length(); ++i)
        {
            if (map.containsKey(s.charAt(i)))
                j = Math.max(j,map.get(s.charAt(i))+1);
            map.put(s.charAt(i),i);
            max = Math.max(max,i-j+1);
        }
        return max; 
        
    }
}