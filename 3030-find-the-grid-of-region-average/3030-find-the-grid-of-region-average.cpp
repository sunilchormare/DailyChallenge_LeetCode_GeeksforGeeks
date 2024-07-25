class Solution {

public:
    vector<vector<int>> resultGrid(vector<vector<int>>& v, int k) {
        int r=v.size(),c=v[0].size();
        map<pair<int,int>,pair<int,int>>m;
        for(int i=0;i<r-2;i++) {
            for(int j=0;j<c-2;j++) {
                int s=0;
                int f=0;
                for(int x=i;x<i+3;x++) {
                    for(int y=j;y<j+3;y++) {
                        s=s+v[x][y];
                        if(x+1<i+3) {
                            if(abs(v[x][y]-v[x+1][y])>k) {
                                f=1;
                                break;
                            }
                        }
                        if(y+1<j+3) {
                            if(abs(v[x][y]-v[x][y+1])>k) {
                                f=1;
                                break;
                            }
                        }
                            
                    }
                    if(f==1)
                        break;
                }
                if(f==1) {
                    continue;
                }
                s=s/9;
                for(int x=i;x<i+3;x++) {
                    for(int y=j;y<j+3;y++) {
                        if(m.find({x,y})!=m.end()) {
                            pair<int,int>p=m[{x,y}];
                            m[{x,y}]={p.first+s,p.second+1};
                        }
                        else {
                            m[{x,y}]={s,1};
                        }
                        
                    }
                }
            }
        }
        
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(m.find({i,j})==m.end()) {
                    ans[i][j]=v[i][j];
                    continue;
                }
                pair<int,int>p=m[{i,j}];
                int s=p.first/p.second;
                ans[i][j]=s;
            }
        }
        return ans;
    }
};