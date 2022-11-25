class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // sort(arr.begin(),arr.end());
        // int sum=0;
        // for(int i=0;i<arr.size();++i)
        // {
        //     for(int j=i;j<arr.size();++j)
        //     {
        //         sum+=arr[i];
        //     }
        // }
        // return sum;
        
        arr.insert(begin(arr), 0);
        
        int n = size(arr), mod = 1e9 + 7, sum = 0;
        vector<int> res(n);
        stack<int> s;
        s.emplace(0);
        
        for(int i = 0; i < n; ++i) {
            while(!s.empty() and arr[s.top()] > arr[i])
                s.pop();
            int j = s.top();
            res[i] = res[j] + (i - j) * arr[i];
            s.emplace(i);
        }
        
        for(int i = 0; i < n; ++i)
            sum = (sum + res[i]) % mod;
        
        return sum;
    }
};