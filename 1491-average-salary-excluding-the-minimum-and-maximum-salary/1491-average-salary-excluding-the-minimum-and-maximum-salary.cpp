class Solution {
public:
    double average(vector<int>& salary) {
//         sort(salary.begin(),salary.end());
        
//         double sum=0.0,c=0.0;
//         for(int i=1;i<salary.size()-1;++i)
//         {
//             sum+=salary[i];
//             c++;
//         }
//         return (sum/c);
        
        int mi=INT_MAX,ma=INT_MIN,s=0;
        for(auto i:salary)
            mi=min(mi,i),ma=max(ma,i),s+=i;
        return (s-ma-mi)*1.0/(salary.size()-2);
    }
};