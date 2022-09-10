class Solution {
public:
    vector<vector<vector<int>>> mem;
    int recursion(vector<int> &prices,int n,int k,int pos,bool brought)
    {
        if(k==0||pos>=n) return 0;
        if(mem[brought][k][pos]!=-1)
            return mem[brought][k][pos];
        int sum=recursion(prices,n,k,pos+1,brought);
        if(brought)
            sum=max(sum,recursion(prices,n,k-1,pos+1,false)+prices[pos]);
        else
            sum=max(sum,recursion(prices,n,k,pos+1,true)-prices[pos]);
    mem[brought][k][pos]=sum;
    return sum;
        
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        mem.resize(2,vector<vector<int>>(k+1,vector<int>(prices.size(),-1)));
        return recursion(prices,n,k,0,false);
    }
};