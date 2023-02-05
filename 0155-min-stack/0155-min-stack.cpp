class MinStack {
    vector<int> min;
    vector<int> s;
    public:

    
    void push(int x) {
        s.push_back(x);
        if(min.empty()||min.back()>=x)
            min.push_back(x);
    }
    
    void pop() {
        if(s.back()==min.back())
            min.pop_back();
        
    s.pop_back();
    }
    
    int top() {
        if(!s.empty())
        return s.back();
        
        return -1;
    }
    
    int getMin() {
        if(!min.empty())
        return min.back();
        
        return -1;
    }
};