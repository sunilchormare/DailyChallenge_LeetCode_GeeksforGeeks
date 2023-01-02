class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wordList)     {
        //bfs
        unordered_map<string,int>mp,vis;
        for(auto word:wordList)mp[word]++;
        queue<pair<string,int>>q;
        q.push({bw,1});
        while(!q.empty())
        {
            string s=q.front().first;
            int lvl=q.front().second;
            q.pop();
            if(s==ew)return lvl;
            if(vis[s]){continue;}
            vis[s]=1;
            for(int i=0;i<s.length();i++)
            {   
                  string wrd=s;
                  for(char j='a';j<='z';j++)
                  { wrd[i]=j;if(mp.count(wrd) and !vis[wrd]) q.push({wrd,lvl+1});}
            }
        }
        return 0;  
    }
};