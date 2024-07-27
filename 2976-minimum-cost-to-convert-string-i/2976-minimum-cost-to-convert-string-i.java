class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        long[][] distance= new long[26][26];
        for(int i=0;i<26;i++){
            distance[i]=new long[26];
            Arrays.fill(distance[i],Integer.MAX_VALUE);
            distance[i][i]=0;
        }
        
        int n=original.length;
        for(int i=0;i<n;i++){
            int a=original[i]-'a';
            int b=changed[i]-'a';
            distance[a][b]=Math.min(distance[a][b],cost[i]);
        }
        
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    distance[i][j]=Math.min(distance[i][j],distance[i][k]+distance[k][j]);                    
                }
            }
        }
        
        int m=source.length();
        long res=0;
        for(int i=0;i<m;i++){
            int a=source.charAt(i)-'a';
            int b=target.charAt(i)-'a';
            if(a!=b){
                long r=distance[a][b];
                if(r==Integer.MAX_VALUE)
                    return -1;
                
                res+=r;
            }
                
        }
        
        return res;
        
    }
}