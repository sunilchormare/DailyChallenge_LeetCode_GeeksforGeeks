class Solution {
public:
    unordered_map<char,int>m;
    unordered_map<char,int>s;

    int isSet(int i, int mask){
        return (mask & (1<<i));
    }

    void setBit(int i, int &mask){
        mask=(mask | (1<<i));
        return;
    }

    void unsetbit(int i, int &mask){
        mask=(mask & ~(1<<i));
        return;
    }

    int val(int mask, vector<string>&w){
        int ans=0;
        for(int i=0;i<w.size();i++){
            if(isSet(i,mask)){
                for(auto j:w[i]){
                    ans+=s[j];
                }
            }
        }
        return ans;
    }

    bool cantake(int ind, int mask, vector<string>&w){
        unordered_map<char,int>temp(m.begin(),m.end());
        for(int i=0;i<w.size();i++){
            if(isSet(i,mask)){
                for(auto j:w[i]){
                    temp[j]--;
                }
            }
        }

        for(auto j:w[ind]){
            if(temp[j]==0)return false;
            temp[j]--;
        }
        return true;
    }

    unordered_map<int,int>dp;

    int f(int i, vector<string>&w, int mask){
        if(i==w.size()){
            return val(mask,w);
        }

        if(dp.count(mask))return dp[mask];

        //take
        int ans=0;
        if(cantake(i,mask,w)){
            setBit(i,mask);
            ans=max(ans,f(i+1,w,mask));
            unsetbit(i,mask);
        }

        //nottake
        ans=max(ans,f(i+1,w,mask));
        return dp[mask]=ans;

    }

    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& sc) {
        for(auto i:l)m[i]++;
        for(int i=0;i<26;i++)s['a'+i]=sc[i];

        return f(0,w,0);

    }
};