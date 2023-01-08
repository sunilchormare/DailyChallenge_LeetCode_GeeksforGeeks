class Solution {
    public int findSubstringInWraproundString(String p) {
         int ans=1,prev_ans=1;
       int arr[]=new int[26];
        arr[p.charAt(0)-'a']=1;
        for (int i=1;i<p.length();i++){
            if ((p.charAt(i-1)-'a'+1)%26==p.charAt(i)-'a') // Checking for continuation
                prev_ans++;
            else
                prev_ans=1;
            if (arr[p.charAt(i)-'a']<prev_ans){
                ans+=prev_ans-arr[p.charAt(i)-'a'];
                arr[p.charAt(i)-'a']=prev_ans;
            }
        }
        return ans;
    }
}