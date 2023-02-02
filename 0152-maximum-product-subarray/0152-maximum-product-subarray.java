class Solution {
    public int maxProduct(int[] A) {
    int n = A.length, res = A[0], l = 0, r = 0;
       
        for (int i = 0; i < n; i++) {
            l =  (l!=0 ? l : 1) * A[i];
           // cout<<"i="<<i<<" l : "<<l<<endl;
            r =  (r!=0 ? r : 1) * A[n - 1 - i];
           //  cout<<"i="<<i<<" r : "<<r<<endl;
            res = Math.max(res, Math.max(l, r));
           // cout<<" res : "<<res<<endl;
            //cout<<endl;
        }
        return res; 
    }
}