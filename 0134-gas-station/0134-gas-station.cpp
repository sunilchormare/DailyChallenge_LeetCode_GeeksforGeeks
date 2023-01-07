class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        // int size=gas.length;
        // int totalSurplus=0;
        // int surplus=0,s=0;
        // for(int i=0;i<size;i++)
        // {
        //     totalSurplus+=gas[i]-cost[i];
        //     surplus+=gas[i]-cost[i];
        //     if(surplus<0)
        //     {
        //         surplus=0;
        //         s=i+1;
        //     }
        // }
        // return (totalSurplus<0)?-1:s;
        int tank = 0;
        for(int i=0; i<gas.length;i++){
            int last = helper(gas, cost, i);
            if(last == -1){
                return i;
            }
            if(last == -2){
                return -1;
            }
            i = last;
        }
        return -1;
    }
    
    
    public int helper (int [] gas, int cost[], int index){
        int tank = 0;
        for(int i=index; i<gas.length;i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                return i;
            }
        }
        for(int i=0; i<index;i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                return -2;
            }
        }
        return -1;
    }
}