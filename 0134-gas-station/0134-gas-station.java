class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size=gas.size();
        int totalSurplus=0;
        int surplus=0,s=0;
        for(int i=0;i<size;i++)
        {
            totalSurplus+=gas[i]-cost[i];
            surplus+=gas[i]-cost[i];
            if(surplus<0)
            {
                surplus=0;
                s=i+1;
            }
        }
        return (totalSurplus<0)?-1:s;
    }
};