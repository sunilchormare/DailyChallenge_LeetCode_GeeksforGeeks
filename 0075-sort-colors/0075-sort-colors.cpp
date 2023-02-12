class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
     int low=0,med=0;
     int high=nums.size()-1;
     
        while(med<=high)
        {
            switch(nums[med])
            {
                case 0: swap(nums[low++],nums[med++]);
                    break;
                case 1:
                    med++;
                    break;
                case 2:
                    swap(nums[med],nums[high--]);
                    break;
                    
            }
        }
         
    }
};