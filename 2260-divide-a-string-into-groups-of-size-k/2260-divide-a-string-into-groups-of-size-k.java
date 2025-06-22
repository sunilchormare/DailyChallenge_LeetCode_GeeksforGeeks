class Solution {
    public String[] divideString(String s, int k, char fill) {
       String[] res = new String[(s.length()+k-1)/k];
    StringBuilder sb = new StringBuilder();
    int o = 0;
    
    //add to array
    for(int i=0;i<s.length();i++){
        sb.append(s.charAt(i));
        if(i%k==k-1){
            res[o++] = sb.toString();
            sb = new StringBuilder();
        }
    }
    
    //fill if needed
    if(o!=res.length){
     while(sb.length()!=k)
            sb.append(fill);
        res[o] = sb.toString();
    }
    
    return res; 
    }
}