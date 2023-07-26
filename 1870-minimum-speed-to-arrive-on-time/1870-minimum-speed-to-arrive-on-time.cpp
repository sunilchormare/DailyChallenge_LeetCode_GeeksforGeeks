class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
         int n = dist.size();
        int mini = 1, maxi = 10000000;
        int ans = -1;
        while(mini <= maxi){
            int mid = (maxi + mini)/2;
            double sum = 0;
            for(int i = 0; i<n-1; ++i){
                sum += ceil( ( (double) dist[i]) /mid);
            }
            sum = sum + ( ( (double) dist[n-1]) /mid);
            if(sum > hour){
                mini = mid+1;
            }else{
                ans = mid;
                maxi = mid-1;
            }
        }
        return ans;
    }
};