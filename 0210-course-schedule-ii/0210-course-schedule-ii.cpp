class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
     vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto i : pre){
            
            int u = i[1], v = i[0];
            
            adj[u].push_back(v);
            indegree[v]++; // [0(u),1(v)] ==> 0--->1 , increase the indegree of v
        }
        
        queue<int> q;
        
        for(int i = 0; i < indegree.size();i++)
        {
            if(indegree[i] == 0)
                q.push(i); // insert the nodes not indegree[i]
                
        }
        
        vector<int> res;
        
        while(!q.empty()){
            
            int s = q.front();
            q.pop();
            res.push_back(s);
            for(auto child : adj[s]){
                
                indegree[child]--;
                if(indegree[child] == 0 )
                    q.push(child);
            }
            
        }
        
        
        if(res.size() == n)
            return res;
        else
            return {}; 
    }
   
    
};