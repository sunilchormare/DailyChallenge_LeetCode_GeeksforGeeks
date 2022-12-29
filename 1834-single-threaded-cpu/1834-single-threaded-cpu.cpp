class Solution {
public:
    static bool cmp(pair<vector<int>,int>& a,pair<vector<int>,int>& b)
    {
        if(a.first[0]!=b.first[0])
        {
            return a.first[0]<b.first[0];
        }
        return a.first[1]<b.first[1];
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<pair<vector<int>,int>> temp;
        for(int i=0;i<tasks.size();++i)
        {
            temp.push_back({tasks[i],i});
        }
        sort(temp.begin(),temp.end(),cmp);
        long long time=temp[0].first[0],i=1,n=tasks.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        q.push({temp[0].first[1],temp[0].second});
        vector<int> ans;
        while(i<n || !q.empty())
        {
            while(i<n && temp[i].first[0]<=time)
            {
                q.push({temp[i].first[1],temp[i].second});
                i++;
            }
            if(q.empty() && i<n)
            {
                time=temp[i].first[0];
                q.push({temp[i].first[1],temp[i].second});
                i++;
            }
            auto t1=q.top();
            q.pop();
            ans.push_back(t1.second);
            time+=t1.first;
        }
        return ans;
    }
};