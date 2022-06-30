class Solution {
public:
    int minMoves2(vector<int>& nums) {
//         int n=nums.size();
//         int count=0;
//         vector<int> a(n);
//         for(int i=0;i<n;++i)
//         {
//             for(int j=0;j<n;++j)
//             {
//                 if(i==j) continue;
//                 else
//                     count+=abs(nums[j]-nums[i]);
//                  cout<<count<<" ";
//             }
//             a[i]=count;
//         }
//          for(int i=0;i<n;++i)
//            cout<<a[i]<<" "<<endl;
//             int mini=0;
//         for(int i=0;i<n;++i)
//         {
//             if(a[i]<mini)
//                 mini=a[i];
            
//         }
//         return mini;
        
        sort(nums.begin(),nums.end());
        int i = 0, j = nums.size()-1;
        int count = 0;
        while(i < j){
            count += nums[j]-nums[i];
            i++;
            j--;
        }
        return count;
    }
};