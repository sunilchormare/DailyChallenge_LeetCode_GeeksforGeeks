class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        
        double sum=0.0,c=0.0;
        for(int i=1;i<salary.size()-1;++i)
        {
            sum+=salary[i];
            c++;
        }
        return (sum/c);
    }
};