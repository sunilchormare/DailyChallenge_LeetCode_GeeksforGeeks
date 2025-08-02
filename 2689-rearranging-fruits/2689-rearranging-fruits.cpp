class Solution {
public:
   typedef long long ll; 
     
    long long minCost(vector<int>& v11, vector<int>& v22) { 
        map<ll,ll> m; 
        int n=v11.size(); 
        ll x=v22[n-1]; 
         
        for(int i=0;i<n;i++){ 
            m[v11[i]]++; 
            m[v22[i]]--; 
        } 
         
        bool flag=false; 
        v11.clear(); 
    v22.clear(); 
    
    ll mi = x; 
    
    for(auto i:m) 
    { 
     mi = min(mi, i.first); 
     x = abs(i.second); 
    
     if(x%2) 
      flag = true; 
    
     x = i.second; 
    
     if(x > 0) 
     { 
      x /= 2; 
    
      while(x--) 
       v11.push_back(i.first); 
     } 
     else if(x < 0) 
     { 
      x = abs(x)/2; 
    
      while(x--) 
       v22.push_back(i.first); 
     } 
    } 
    
    if(flag) 
    { 
     return -1; 
    } 
    
    reverse(v22.begin(),v22.end()); 
    
    ll ans = 0; 
    
    for(int i=0;i<v11.size();i++) 
     ans += min(2*mi,1ll*min(v11[i],v22[i])); 
    
    return ans; 
         
    }
};