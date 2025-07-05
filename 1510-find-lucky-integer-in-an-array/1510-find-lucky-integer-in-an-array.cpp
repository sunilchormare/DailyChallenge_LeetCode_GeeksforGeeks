class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        unordered_map<int,int> map;
        for(int a:arr)
        {
            map[a]++;
        }

        vector<int> a;
        int res=-1;
        for(int i=0;i<arr.size();++i)
        {
          if(map[arr[i]]==arr[i])
              res=max(arr[i],res);  
        }

        return res;
    }
};