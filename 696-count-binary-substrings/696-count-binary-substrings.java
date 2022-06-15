class Solution {
    public int countBinarySubstrings(String s) {
        int count=0,i=1,prev=0,cur=1;
        while(i<s.length())
        {
            if(s.charAt(i-1)!=s.charAt(i))
            {
                count+=Math.min(prev,cur);
                prev=cur;
                cur=1;
            }
            else
                cur++; 
            i++;
        }
        count+=Math.min(prev,cur);
        return count;
    }
}