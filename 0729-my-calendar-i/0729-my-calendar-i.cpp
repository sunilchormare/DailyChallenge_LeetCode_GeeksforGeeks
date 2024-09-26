class MyCalendar {
public:
     vector<pair<int, int>> books;
public:    
    bool book(int start, int end) 
    {
        for (pair<int, int> p : books)
        {// cout<<max(p.first,start)<<endl;
            if (max(p.first, start) < min(end, p.second)) 
                return false;
        }
        books.push_back({start, end});
        return true;
    }
};

