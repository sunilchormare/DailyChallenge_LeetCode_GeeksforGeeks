class Solution {
public:
    string reformat(string s) {
        vector<char> alpha;
        vector<char> numbers;
        // Creating a vector for storing alpha and numeric separately
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z'){
                alpha.push_back(s[i]);
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                numbers.push_back(s[i]);
            }
        }
        string ans = "";
        int m = alpha.size();
        int n = numbers.size();
        // The number of alpha and numeric should be either equal or differ by 1 to make string valid
        if(abs(m-n) <= 1){
            if(m>=n){
                int i;
                for(i=0 ; i<n ; i++)
                {
                    ans += alpha[i];
                    ans += numbers[i];
                }
                if(m != n){
                    ans += alpha[i];
                }                
            }
            else{
                int i;
                for(i=0 ; i<m ; i++)
                {
                    ans += numbers[i];
                    ans += alpha[i];                    
                }
                ans += numbers[i];
            }
            
            return ans;    
        }
        // else string is invalid
        return ans;
    }
};