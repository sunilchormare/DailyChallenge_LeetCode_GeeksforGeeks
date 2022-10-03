class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
     
//         int cost=0;
//         for(int i=1;i<neededTime.size();++i)
//         {
//             int temp=0;
//             if(colors[i]==colors[i-1])
//                 temp=min(neededTime[i],neededTime[i-1]);
//             cost+=temp;
//         }
//         return cost;
        
        int totalTime = 0, currMaxTime = 0;
        for (int i = 0; i < colors.size(); ++i) {
            if (i > 0 && colors[i] != colors[i - 1]) {
                currMaxTime = 0;
            }
            totalTime += min(currMaxTime, neededTime[i]);
            
            currMaxTime = max(currMaxTime, neededTime[i]);
           // cout<<"i : "<<i<<" totalTime :  "<<totalTime<<" currMaxTime : "<<currMaxTime<<endl;
        }
        return totalTime;
    }
};