class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
       int len = 0, count = 0;
      for (auto a: sentences) {
        for (auto b: a) {
          if (b == ' ')
            count++;
        }

        len = max(count + 1, len);
        count = 0;

      }

      return len;
    }
};