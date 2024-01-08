class Solution {
public:
int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int cap) {
        int n1 = b.size() , n2 = p.size() , j=0 , ans , prev=-1;
        sort(b.begin() , b.end());
        sort(p.begin() , p.end());
        
        for(int i=0 ; i<n1 ; i++){
            int c = 0;
            while(c<cap && j<n2 && p[j]<=b[i]){
                if(p[j]-1!=prev) ans = p[j]-1; 
                prev = p[j];
                c++;
                j++;
            }
            if(c<cap && b[i]!=prev) ans = b[i];
        }
        return ans;
    }
};