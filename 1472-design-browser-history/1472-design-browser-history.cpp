class BrowserHistory {
public:
 stack<string>s1,s2;
    BrowserHistory(string homepage) {
        s1.push(homepage);
    }
    void visit(string url) {
        s1.push(url);
        while(!s2.empty()) s2.pop();
    }
    string back(int steps) {
        while(steps-- and s1.size()>1) {s2.push(s1.top());s1.pop();}
        return s1.top();
    }
    string forward(int steps) {
        while(steps-- and !s2.empty()){s1.push(s2.top());s2.pop();}
        return s1.top();
    }
};

