class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
         int n=edges.size();
        vector<int> a[n];
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1){
                a[i].push_back(edges[i]);
            }
        }
        vector<int> x(n,1e8),y(n,1e8);
        queue<int> q;
        q.push(node1);
        
       x[node1]=0;
        while(!q.empty()){
    
            int sq=q.size();
            for(int i=0;i<q.size();i++){
                auto it=q.front();
                q.pop();
                for(auto itr:a[it]){
                    if(x[itr]==1e8){
                        x[itr]=x[it]+1;
                        q.push(itr);
                    }
                }
            }
        }
          q.push(node2);
        
       y[node2]=0;
        while(!q.empty()){
    
            int sq=q.size();
            for(int i=0;i<q.size();i++){
                auto it=q.front();
                q.pop();
                for(auto itr:a[it]){
                    if(y[itr]==1e8){
                        y[itr]=y[it]+1;
                        q.push(itr);
                    }
                }
            }
        }
        int w=INT_MAX;
        int z=-1;
        for(int i=0;i<n;i++){
            if(x[i]!=1e8&&y[i]!=1e8){
int p=max(x[i],y[i]);
                if(w>p){
                    w=p;
                    z=i;
                }
            }
        }
        return z;
    }
};