class Solution {
public:
    int wateringPlants(vector<int>& p, int capacity) {
//         int n=plants.size();
//         //if(plants[0]<=capacity&&n==1) return 1;
//         int ans=0;
//         int tem=capacity;
//         for(int i=0;i<n;++i)
//         {
//             if(plants[i]<=capacity)
//             {
//                 ans++;
//                 capacity-=plants[i];
//             }
//             else
//             {
                
//                 capacity=tem;
//                 capacity-=plants[i];
//                 ans+=(2*i)+1;
//             }
//         }
//         return ans;
        
        int res = 0, can = capacity;
    for (int i = 0; i < p.size(); ++i) {
        if (can < p[i]) {
            res += i * 2;
            can = capacity;
        }
        can -= p[i];
    }
    return res + p.size();    
    }
};