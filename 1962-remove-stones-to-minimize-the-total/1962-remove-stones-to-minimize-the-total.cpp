class Solution {
public:
    //int minStoneSum(vector<int>& piles, int k) {
//         int sum=0,n=piles.size();
//         //if(k>n) return 1;
//         sort(piles.begin(),piles.end());
        
//             for(int i=n-1;i>=0,k>0;i--,k--)
//                 piles[i]=piles[i]-floor(piles[i]/2);
//           for(int i=0;i<n;++i)
//               sum+=piles[i];
        
//         return sum;
//}  
        
        int minStoneSum(vector<int>& A, int k) {
        priority_queue<int> pq(A.begin(), A.end());
        int res = accumulate(A.begin(), A.end(), 0);
        while (k--) {
            int a = pq.top();
            pq.pop();
            pq.push(a - a / 2);
            res -= a / 2;
        }
        return res;
    }
    
};