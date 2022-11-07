class Solution {
    public int maximum69Number (int num) {
//         String s=Integer.toString(num);
//         char n[]=s.toCharArray();
//         int maxi=0,count=0;
//         for(int i=0;i<n.length;++i)
//         {
//             char c=n[i];
//             if(n[i]=='6') 
//             {
//                 n[i]='9';
//                 int temp=Integer.parseInt(new String(n));
//                 maxi=Math.max(maxi,temp);
//                 n[i]=c;
//             }
//             else count++;
            
            
//         }
//         return count==n.length?num:maxi;
        
         return Integer.parseInt(("" + num).replaceFirst("6", "9"));
    }
}