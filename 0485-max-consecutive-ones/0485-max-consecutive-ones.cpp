class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
     int count=0;
      int maxi=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==1)
            {
                count++;
            }
            else
            {
                count=0;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }

};

/*int main()
{
    
    Solution s;
    vector<int> v;
    int t;
    while(cin>>t)
    {
        v.push_back(t);
     }
    cout<<s.findMaxConsecutiveOnes(v);
    return 0;
}
*/