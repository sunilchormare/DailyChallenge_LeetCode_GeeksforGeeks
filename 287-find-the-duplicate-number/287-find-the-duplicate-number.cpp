class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     // int n=nums.size()-1;
     //    int sumArr=0;
     //    for(int i:nums)
     //        sumArr+=i;     
     //    int sum=(n*(n+1))/2;
     //    cout<<sum;
     //    return sumArr-sum;
    map<int,int> m;
        for(int i:nums)
            m[i]++;
    for(auto i:m)
        if(i.second>=2)
            return i.first;
    return 0;
    }
};