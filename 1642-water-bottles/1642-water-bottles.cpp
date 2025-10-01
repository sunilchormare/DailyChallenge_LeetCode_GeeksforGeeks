class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
         int initial = numBottles;
        while(numBottles >= numExchange){

            initial += (numBottles/numExchange);
            numBottles= (numBottles/numExchange) + (numBottles % numExchange);
            
        }
        return initial;
    }
};