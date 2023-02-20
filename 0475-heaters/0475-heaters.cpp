class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for(int i = 0; i < houses.size(); i++){
            // Binary search
            int l = 0;
            int r = heaters.size() - 1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(heaters[mid] == houses[i]){
                    l = mid - 1;
                    r = mid + 1;
                    break;
                }
                else if(heaters[mid] < houses[i])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            double idx = (l + r) / 2.0;
            int right = (idx > heaters.size() - 1)? INT_MAX : heaters[(int)(idx + 0.5)] - houses[i];
            int left = (idx < 0)? INT_MAX : houses[i] - heaters[(int)idx];
            res = max(res, min(right, left));
        }
        return res;
    }
};