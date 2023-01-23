class Solution {
    public boolean checkIfCanBreak(String c1, String c2) {
        char []s1=c1.toCharArray();
        char []s2=c2.toCharArray();
        Arrays.sort(s1);
        Arrays.sort(s2);
        int i=0;
        while(i<s1.length&&s1[i]>=s2[i]) i++;
        if(i==s1.length) return true;
        i=0;
        while(i<s1.length&&s2[i]>=s1[i]) i++;
        return i==s1.length;
    }
}