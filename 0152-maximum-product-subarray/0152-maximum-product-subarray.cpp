class Solution {
public:
    int maxProduct(vector<int>& A) {
  
        int n = A.size(), res = A[0], l = 0, r = 0;
       
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * A[i];
           // cout<<"i="<<i<<" l : "<<l<<endl;
            r =  (r ? r : 1) * A[n - 1 - i];
           //  cout<<"i="<<i<<" r : "<<r<<endl;
            res = max(res, max(l, r));
           // cout<<" res : "<<res<<endl;
            //cout<<endl;
        }
        return res; 
    }
};