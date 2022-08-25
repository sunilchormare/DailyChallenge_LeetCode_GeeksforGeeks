class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
          int a[]=new int[26];
          //cout<<a[magazine[0]-'a'];
        for(int i=0;i<magazine.length();++i)
            a[magazine.charAt(i)-'a']++;
        for(int i=0;i<ransomNote.length();++i)
             if(--a[ransomNote.charAt(i)-'a']<0)
                 return false;
        return true;
    }
}