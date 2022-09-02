class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
      vector<int> ret;
        for (int i=0; i<input.size(); i++) {
            if (input[i] == '-' ||
                input[i] == '*' ||
                input[i] == '+' ) {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for (int p1 :   left) {
                    for (int p2 :   right) {
                        int c = 0;
                        switch (input[i]) {
                            case '+': c = p1+p2;
                                break;
                            case '-': c = p1-p2;
                                break;
                            case '*': c = p1*p2;
                                break;
                        }
                        ret.push_back(c);
                    }
                }
            }
        }
        if (ret.size() == 0) {
            ret.push_back(stoi(input));
        }
        return ret;
    }
};