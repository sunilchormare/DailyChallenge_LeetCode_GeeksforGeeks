class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
//         int n=asteroids.size();
//         sort(asteroids.begin(),asteroids.end());
//         int sum=0;
//         for(int i:asteroids)
//             sum+=i;
//         sum=sum-asteroids[n-1];
//         sum+=mass;
//         if(asteroids[n-1]<=sum)
//             return true;
//         else 
//             return false;
        
//         return false;
        
        
        long m = mass;
        sort(asteroids.begin(),asteroids.end());
        for (int ast : asteroids) {
            if (m < ast) {
                return false;
            }
            m += ast;
        }
        return true;
    }
};