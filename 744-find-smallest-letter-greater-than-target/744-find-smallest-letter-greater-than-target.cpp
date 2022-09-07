class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target>=letters[letters.size()-1]) return letters[0];
        int left=0;
        int right=letters.size();
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(letters[mid]<=target)
                left=mid+1;
            else
                right=mid;
        }
        return letters[right];
    }
};