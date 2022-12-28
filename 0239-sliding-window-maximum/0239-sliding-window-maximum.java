class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int n=nums.size();
        // vector<int> res;
        // for(int i=0;i<=n-k;++i)
        // {
        //     int maxi=0;
        //     for(int j=i;j<i+k;++j)
        //          maxi=max(maxi,nums[j]);
        //     res.push_back(maxi);
        // }
        // return res;
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};