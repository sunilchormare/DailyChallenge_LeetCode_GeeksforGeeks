class Solution {
public:
    int countArrangement(int n) {
    vector<int> vis(n+1,0);
    return helper(n,1,vis);
}
int helper(int n, int j, vector<int>vis) {
    if(j>n) {
        return 1;
    }
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        if(!vis[i]&&(j%i==0 || i%j==0)) {
            vis[i]=1;
            cnt += helper(n,j+1,vis);
            vis[i]=0;
        }
    }
    return cnt;
}
};