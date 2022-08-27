class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
//         int n=intervals.size();
//         vector<int> res(n);
//         int count=1;
//         for(int i=0;i<n;++i)
//         {
//             for(int j=0;j<n;++j)
//             {
                
//                 if(i==j) continue;
//                 if(intervals[i][j]<=intervals[i][j])
//                 {
//                     res.push_back(j);
//                     break;
//                 }
//                 else
//                     count++;
//             }
//             if(count==n)
//                 res.push_back(-1);
//             count=1;
//         }
//         return res;
//     
     vector<int> ans(intervals.size());
        map<int, int> m;
        for(int i = 0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;
        for(int i = 0; i < intervals.size(); i++) 
               ans[i]  = m.lower_bound(intervals[i][1])!=end(m)?m.lower_bound(intervals[i][1]) -> second:-1;
        return ans;
    }
        
};