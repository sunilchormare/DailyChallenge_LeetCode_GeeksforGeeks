class Solution {
    public long smallestNumber(long num) {
       String s=String.valueOf(num);
    char[] ans=s.toCharArray();
     Arrays.sort(ans);
    if(num<0){
     String ss="-";
        for(int i=ans.length-1;i>=1;i--){
            ss+=ans[i];
        }
        Long ln=Long.parseLong(ss);  
        return ln;
         }  
    else{
        String sss="";
    if(ans[0]=='0'){
        int k=1;
        while(k<ans.length && ans[k]=='0'){
            k++;
        }
        if(k==ans.length)return 0;
        swap(ans,k);
    }
      for(int i=0;i<ans.length;i++){
            sss+=ans[i];
        }
     Long ln=Long.parseLong(sss);  
        return ln;
         
    }
}
public void swap(char [] ans,int k){
    char ch=ans[k];
    ans[k]=ans[0];
    ans[0]=ch;
}
 
    
}