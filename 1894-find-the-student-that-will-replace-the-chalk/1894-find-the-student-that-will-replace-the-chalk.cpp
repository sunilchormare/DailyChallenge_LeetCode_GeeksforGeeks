class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum=0;
        for(int i=0;i<chalk.size();i++) sum+=chalk[i];
        int left=(int)(k%sum);
        for(int i=0;i<chalk.size();i++) {
            if(left<chalk[i]) return i;
            left-=chalk[i];
        }
        return 0;
    }
};