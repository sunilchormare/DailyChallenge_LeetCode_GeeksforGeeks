class Solution {
public:
    long long smallestNumber(long long num) {
       string s = to_string(num);
   if (num > 0) {
   	sort(s.begin(), s.end());
   	if (s[0] == '0') {
   		int i = 0;
   		while (s[i] == '0') {
   			i++;
   		}
   		swap(s[0], s[i]);
   	}
   }
   else if (num == 0)
   	return num;
   else {
   	sort(s.begin() + 1, s.end(), greater<char>());
   }
   return stoll(s); 
    }
};