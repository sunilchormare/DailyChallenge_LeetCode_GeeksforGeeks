class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        map<int,int> m;
        for(int a:nums)
            m[a]++;

      for(auto i : m )
          if(i.second==2)
              res.push_back(i.first);
        
       return res;
    }
};