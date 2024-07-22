class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
           vector<pair<int,int>> store;
        for(int i = 0; i<values.size(); i++)
            store.push_back({values[i],labels[i]});
        
        sort(store.begin(),store.end());
        reverse(store.begin(),store.end());
        
        unordered_map<int,int> mp;
        int sum = 0, count = 0;
        
        for(int i = 0; i<store.size(); i++)
            if(++mp[store[i].second] <= useLimit && count++ < numWanted)
                sum += store[i].first;
        
        return sum;
    
    }
};