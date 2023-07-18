class Solution {
    public String shortestSuperstring(String[] words) {
        int n=words.length;
        int dist[][] = new int[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                for(int k=0; k<words[i].length(); k++){
                    if(words[j].startsWith(words[i].substring(k))){
                        dist[i][j]=words[i].length()-k;
                        break;
                    }
                }
            }
        }

        int dp[][] = new int[1<<n][n];
        int path[][] = new int[1<<n][n];

        for(int mask=0; mask<(1<<n); mask++){
            for(int curNode=0; curNode<n; curNode++){
                // check if mask contains curNode
                if((mask&(1<<curNode))==0) continue;
                for(int adjNode=0; adjNode<n; adjNode++){
                    if((mask&(1<<adjNode))==0 && dp[mask|(1<<adjNode)][adjNode]<=dist[curNode][adjNode]+dp[mask][curNode]){
                        dp[mask|(1<<adjNode)][adjNode]=dist[curNode][adjNode]+dp[mask][curNode];
                        path[mask|(1<<adjNode)][adjNode]=curNode;
                    }
                }
            }
        }
        int mask=(1<<n)-1; int node=0; int maxVal=-1;

        for(int i=0; i<n; i++){
            if(dp[mask][i]>maxVal){
                maxVal=dp[mask][i];
                node=i;
            }
        }

        String res[] = new String[n];
        int idx=n-1;
        while(idx>=0){
            int temp = path[mask][node];
            res[idx--]=words[node];
            mask^=(1<<node);
            node = temp;
        }        

        HashMap<String,Integer> map = new HashMap<>();
        for(int i=0; i<n; i++)map.put(words[i],i);

        StringBuilder ans = new StringBuilder();
        ans.append(res[0]);
        for(int k=1; k<n; k++){
            int i=map.get(res[k-1]);
            int j=map.get(res[k]);

            ans.append(res[k].substring(dist[i][j]));
        }

        return ans.toString();
    }
}