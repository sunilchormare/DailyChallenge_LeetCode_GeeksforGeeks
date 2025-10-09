class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
    vector<long long> endTime(skill.size(), 0);
    for(int i = 0; i < mana.size(); ++i){
        long long t = 0, maxDiff = 0;
        for(int j = 0; j < skill.size(); ++j){
            maxDiff = max(maxDiff, endTime[j] - t);
            t += (long long)skill[j] * (long long)mana[i];
            endTime[j] = t;
        }
        for(int j = 0; j < skill.size(); ++j) endTime[j] += maxDiff;
    }
    return endTime.back();
}
};