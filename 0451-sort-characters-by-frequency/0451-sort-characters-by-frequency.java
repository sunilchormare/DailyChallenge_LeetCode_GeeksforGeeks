class Solution {
public:
    string frequencySort(string s) {
       // string res="";
       // vector<pair<int,char>> hash('z'+1,{0,0});
       // for(char c:s)
       //     hash[c]={hash[c].first+1,c};
       //  sort(hash.begin(),hash.end());
       //  for(auto i:hash)
       //  {
       //      res=string(i.first,i.second)+res;
       //  }
       //  return res;
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        for(auto i:mp)
            pq.push(make_pair(i.second,i.first));
        string ans="";
        while(!pq.empty())
        {
            int a=pq.top().first;
            char b= pq.top().second;
            for(int i=0;i<a;i++)
            {
                ans+=b;
            }
            pq.pop();
        }
        return ans;
    }
};