class Solution {
public:
    static bool placeWordInCrossword(const vector<vector<char>>& board, const string& word) {
        const int m = size(board);
        const int n = size(board[0]);
        const int strlen = size(word);

        auto check = [&] (string_view s) {
            bool flag = true;
            for (int i = 0; i < strlen; ++i)
                if (' ' != s[i] && s[i] != word[i]) {
                    flag = false;
                    break;
                }
            if (flag)
                return true;
            for (int i = 0; i < strlen; ++i)
                if (' ' != s[i] && s[i] != word[strlen - i - 1])
                    return false;
            return true;
        };

        auto horizontal = [&] () {
            for (auto& line : board)
                for (int j = 0; j < n; ++j)
                    if ('#' == line[j]) {
                        continue;
                    } else if (' ' == line[j] || word[0] == line[j] || word.back() == line[j]) {
                        string str;
                        while (j < n && '#' != line[j])
                            str += line[j++];
                        if (size(str) == strlen && check(str))
                            return true;
                    } else {
                        while (j < n && line[j] != '#')
                            ++j;
                    }
            return false;
        };

        auto vertical = [&] () {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if ('#' == board[j][i]) {
                        continue;
                    } else if (' ' == board[j][i] || word[0] == board[j][i] || word.back() == board[j][i]) {
                        string str;
                        while (j < m && '#' != board[j][i])
                            str += board[j++][i];
                        if (size(str) == strlen && check(str))
                            return true;
                    } else {
                        while (j < m && board[j][i] != '#')
                            ++j;
                    }
            return false;
        };

        return horizontal() || vertical();
    }
};