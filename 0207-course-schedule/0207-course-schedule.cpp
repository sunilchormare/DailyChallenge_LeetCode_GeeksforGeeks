// class Solution {
//     bool isCyclic(vector<vector<int>>& adj,vector<int>& visited,int curr)
//     {
//         if(visited[curr]==2)
//             return true;
        
//         visited[curr] = 2;
//         for(int i=0;i<adj[curr].size();++i)
//             if(visited[adj[curr][i]]!=1)
//                 if(isCyclic(adj,visited,adj[curr][i]))
//                     return true;
        
//         visited[curr] = 1;
//         return false;
//     }
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
        
//         vector<vector<int>> adj(numCourses);
//         //Make adjacency matrix (Directed graph)
//         for(int i=0;i<prerequisites.size();++i)
//             adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
//         vector<int> visited(numCourses,0);
//         for(int i=0;i<numCourses;++i)
//             if(visited[i]==0)
//                 if(isCyclic(adj,visited,i))
//                     return false;
        
//         return true;
//     }
// };

class Solution {
public:
    // bool acyclic(vector<vector<int>>& graph, int node, vector<bool>& visit, vector<bool>& done) {
    //     if (visit[node]) return false;
    //     if (done[node]) return true;
    //     visit[node]= true;
    //     done[node]= true;
    //     for (int adj: graph[node]) {
    //         if (acyclic(graph, adj, visit, done)== false) 
    //             return false;
    //     }
    //     visit[node]= false;
    //     return true;
    // }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // int n= numCourses;
        // vector<vector<int>> graph(n);
        // for (auto x: prerequisites) graph[x[1]].push_back(x[0]);
        // vector<bool> visit(n, false), done(n, false);
        // for (int i= 0; i<n; i++) {
        //     if (done[i]== false and acyclic(graph, i, visit, done)== false) return false;
        // }
        // return true;
        
         vector<vector<int>> G(n);
        vector<int> degree(n, 0), bfs;
        for (auto& e : prerequisites)
            G[e[1]].push_back(e[0]), degree[e[0]]++;
        for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        return bfs.size() == n;
    }
};