class Solution {
    public boolean possibleBipartition(int N, int[][] dislikes) {
    List<Integer>[] arr=new List[N+1];
        for(int i=1;i<=N;i++)arr[i]=new ArrayList<>();
        for(int i=0;i<dislikes.length;i++){
            arr[dislikes[i][0]].add(dislikes[i][1]);
            arr[dislikes[i][1]].add(dislikes[i][0]);
        }
        int[] parent=new int[N+1];
        for(int i=1;i<=N;i++)parent[i]=i;
        for(int i=1;i<=N;i++){
            List<Integer> list=arr[i];
            if(list.isEmpty())continue;
            int curP=list.get(0);
            if(parent[findUnion(i,parent)]==parent[findUnion(curP,parent)])return false;
            for(int j=1;j<list.size();j++){
                if(parent[findUnion(i,parent)]==parent[findUnion(list.get(j),parent)])return false;
                parent[list.get(j)]=parent[curP];
            }
        }
        return true;
    }
    
    public int findUnion(int i,int[] parent){
        if(i!=parent[i])parent[i]=findUnion(parent[i],parent);
        return parent[i];
    }
}