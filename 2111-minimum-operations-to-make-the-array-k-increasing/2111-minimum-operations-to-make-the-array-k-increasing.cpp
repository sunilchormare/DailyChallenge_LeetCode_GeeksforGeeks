class Solution {
public:
    int LIS(vector<int>& vec){
        int n=vec.size();
        
        vector<int> lis; 
        lis.push_back(vec[0]);
        
        for(int i=1; i<n; ++i){
            if(vec[i] >= lis.back()) lis.push_back(vec[i]);
            else{
                auto lb = upper_bound(lis.begin(), lis.end(), vec[i]);
                int idx = lb-lis.begin();
                swap(lis[idx], vec[i]);
            }
        }
        return n-lis.size(); //not part of LIS
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size();
        int count = 0;
        for(int i=0; i<k; ++i){
            vector<int> vec;
            for(int j=i; j<n; j=j+k){
                vec.push_back(arr[j]);
            }
            count += LIS(vec);
        }
        return count;
    }
};