class Solution {
public:
   vector<long long> getDistances(vector<int>& arr) {
        std::vector<long long> res(arr.size(), 0);
        std::unordered_map<int, std::vector<long long>> num_to_indices;
        
        for(long long i=0; i < arr.size(); i++) {
            num_to_indices[arr[i]].push_back(i);
        }
        
        for(auto const& ele: num_to_indices) {
            auto const& indices = ele.second;
            for(int i = 1; i < indices.size(); i++) {
                res[indices[0]] += std::abs(indices[i]-indices[0]);
            }
            for(int i = 1; i < indices.size(); i++) {
			    // Not simplifying this line intentionally for better understanding.
                res[indices[i]] = res[indices[i-1]] - (indices[i]-indices[i-1])*(indices.size()-i-1) + (indices[i]-indices[i-1])*(i-1);
            }
        }
        
        return res;
    }
};