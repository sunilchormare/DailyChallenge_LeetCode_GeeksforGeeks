class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> temp={a, b, c};
        sort(temp.begin(), temp.end());
        int x=temp[0], y=temp[1], z=temp[2], minMove=2, maxMove=z-x-2;
        if(z==x+2) minMove=0;
        else if(z<=y+2||y<=x+2) minMove=1;
        return {minMove, maxMove};
    }
};