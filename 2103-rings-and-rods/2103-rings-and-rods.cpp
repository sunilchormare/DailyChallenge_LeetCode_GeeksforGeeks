class Solution {
public:
    int countPoints(string rings) {
    //     int rods[10] = {};
    // for (int i = 0; i < rings.size(); i += 2) 
    // {
    //     int color = rings[i] == 'R' ? 1 : rings[i] == 'G' ? 2 : 4;
    //     rods[rings[i + 1] - '0'] |= color;
    // }
    // return count(begin(rods), end(rods), 7);
        int c[30]={};
        for(int i=0;i<rings.size();i+=2)
        {
           if(rings[i]=='R')c[rings[i+1]-'0']=1;
           else if(rings[i]=='B')c[rings[i+1]-'0'+10]=1;
            else c[rings[i+1]-'0'+20]=1;
        }
        int res=0;
        for(int i=0;i<=9;i++)
            res+=(c[i] && c[i+10] && c[i+20]);
        return res;
    }
};