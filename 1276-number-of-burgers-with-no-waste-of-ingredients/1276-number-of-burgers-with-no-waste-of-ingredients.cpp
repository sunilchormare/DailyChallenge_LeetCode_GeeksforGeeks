class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices%2!=0) return {};
        int jumbo=tomatoSlices/2-cheeseSlices, small=cheeseSlices-jumbo;
        if(jumbo<0||small<0) return {};
        return {jumbo, small};
    }
};