class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        auto gt_cmp = [&nums] (int i, int j) { 
            return nums[i] != nums[j] ? nums[i] > nums[j] : i < j; 
        };
        auto lt_cmp = [&nums] (int i, int j) { 
            return nums[i] != nums[j] ? nums[i] < nums[j] : i < j; 
        };
        
        set<int, decltype(gt_cmp)> left(gt_cmp);
        set<int, decltype(lt_cmp)> right(lt_cmp);
        
        function<double()> median;
        
        if (k & 1) {
            median = [&right, &nums] { return (double) nums[*right.begin()]; };
        } else {
            median = [&left, &right, &nums] { return ((double) nums[*left.begin()] + nums[*right.begin()]) / 2; };
        }
        
        auto balance = [&left, &right] () {
            while (left.size() > right.size()) {
                right.emplace(*left.begin());
                left.erase(left.begin());
            }
        };
        
        int n = nums.size();
        vector<double> ans(n - k + 1);
        
        for (int i = 0; i < k; ++i) left.emplace(i);
        balance(); ans[0] = median();
        
        for (int i = k; i < n; ++i) {
            if (!left.erase(i - k)) right.erase(i - k);
            right.emplace(i), left.emplace(*right.begin()), right.erase(right.begin());
            
            balance(); ans[i - k + 1] = median();
        }
        
        return ans;
    }
};