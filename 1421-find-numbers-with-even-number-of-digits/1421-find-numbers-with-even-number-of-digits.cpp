class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int count=0;
        for(int i:nums)
        {
            string d=to_string(i);
            if(d.size()%2==0)
                count++;
        }
        return count;
    }
};