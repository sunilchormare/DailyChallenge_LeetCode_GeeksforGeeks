class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // set<int> m;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();++i)
        //      m.insert(nums[i]);
        // vector<int> res(k);
        // for(int i=0;i<k;++i)
        //     res[i]=*next(m.begin(),i);;
        // return res;
//         unordered_map<int,int> hm;
//     priority_queue<int> maxHeap;
//     vector<int> res(k);
    
//     for(int i=0;i<nums.size();i++)
//         hm[nums[i]]++;
//     for(auto i:hm){
//         maxHeap.push(i.second);
//         cout<<"i = "<<" ";
//     }
//     for(int i=0;i<k;i++)
//     {
//         res[i]=maxHeap.top();
//         maxHeap.pop();
//     }
        

//     return res;   
        
        unordered_map<int,int> mp;
        for (auto&x: nums) mp[x]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for (auto& p: mp){
            pq.push({p.second, p.first});
            if (pq.size() > k)
                pq.pop();
        }
        
        vector<int> ret;
        while (!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};