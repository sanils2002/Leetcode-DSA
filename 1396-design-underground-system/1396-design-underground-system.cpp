class UndergroundSystem {
private:
    struct Travel {
        string startStation;
        int startTime;
    };

    unordered_map<int, Travel> checkIns; // Stores check-in information
    unordered_map<string, pair<double, int>> travelTimes; // Stores travel times and counts
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        const Travel& checkInInfo = checkIns[id];
        string route = checkInInfo.startStation + "->" + stationName;
        int travelTime = t - checkInInfo.startTime;

        auto& stats = travelTimes[route];
        stats.first += travelTime; // Accumulate total travel time
        stats.second++; // Increment the count of trips on this route

        checkIns.erase(id); // Remove check-in information
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "->" + endStation;
        const auto& stats = travelTimes[route];
        return stats.first / static_cast<double>(stats.second); // Calculate average travel time
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */