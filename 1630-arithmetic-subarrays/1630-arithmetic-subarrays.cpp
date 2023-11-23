class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
      
      vector<bool> res;
       int i=0;
        while(i<l.size())
        {
            int a=l[i],b=r[i];
            vector<int> temp;
            for(int k=a;k<=b;++k)
                temp.push_back(nums[k]);
            
            sort(temp.begin(),temp.end());
           
            int c=1;
            for(int w=1;w<temp.size();++w)
            {
                if(abs(temp[w]-temp[w-1])==abs(temp[1]-temp[0]))
                    c++;
            }
           
            if(c==temp.size())
                res.push_back(true);
            else
                res.push_back(false);
            
            i++;
        }
        
        return res;
    }
};