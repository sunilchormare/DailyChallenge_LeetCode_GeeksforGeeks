class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
//         vector<int> res,res1,res2;
//         for(int i=1;i<arr.size();++i)
//         {
//             for(int j=0;j<i;++j)
//             {
//                 if(i<j)
//  res.push_back(arr[i]),res1.push_back(arr[j]),res2.push_back(arr[i]/arr[j]);
//             }
//         }
//         sort(res.begin(),res.end());
//         sort(res1.begin(),res1.end());
//         sort(res2.begin(),res2.end());
//         vector<int> fi={res[k-1],res[k-1]};
        
//         return fi;
        
         int n=arr.size();
        priority_queue<pair<double,pair<int,int>>>q;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double frac=(double)arr[i]/arr[j]; 
                if(q.size()>=k){
                    if(q.top().first>frac){
                        q.pop();
                        q.push({frac,{arr[i],arr[j]}});
                    }
                }
                else{
                    q.push({frac,{arr[i],arr[j]}});
                }
            }
        }

        vector<int>ans(2);
        ans[0]=q.top().second.first;
        ans[1]=q.top().second.second;
        return ans;
        
    }
}; 
