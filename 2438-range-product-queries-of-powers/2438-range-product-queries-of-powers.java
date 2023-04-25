class Solution {
    public int[] productQueries(int n, int[][] queries) {
         int m = 1000000007;
    int ans[]=new int[queries.length];
    ArrayList<Integer> bint=new ArrayList<>();
    //create power array 
    for(int i = 0; i < 32; ++i){
        if((n & (1<<i)) != 0) bint.add(1<<i);
    }
    int k=0;
    for(int q[]: queries){
        int i = q[0];
        long p = bint.get(i++);
        while(i <= q[1]){
            p = (p * bint.get(i++))%m;
        }
        ans[k++]=(int)p;
    }
    return ans;

    }
}