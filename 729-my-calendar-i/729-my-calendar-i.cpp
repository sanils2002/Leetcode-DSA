class MyCalendar {
protected:
    list<pair<int,int>> calendar;
public:
    MyCalendar() {
        calendar.clear();
    }
    
    bool book(int start, int end) {
        for(auto &date : calendar) {
            if(date.first < end && start < date.second)
                return false;
        }
        calendar.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */