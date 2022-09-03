class Solution {
    void dfs(int num,int n,int k,List<Integer> res)
    {
        if(n==0)
        {
            res.add(num);
            return;
        }
        int last_digit=num%10;
        if(last_digit>=k) dfs(num*10+last_digit-k,n-1,k,res);
        if(k>0&&last_digit+k<10) dfs(num*10+last_digit+k,n-1,k,res);  
    }
    public int[] numsSameConsecDiff(int n, int k) {
    List<Integer> res=new ArrayList<>();
    for(int d=1;d<10;++d)
    {
      dfs(d,n-1,k,res);
    }
    return res.stream().mapToInt(i->i).toArray();
    }
}