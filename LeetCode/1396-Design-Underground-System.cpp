class UndergroundSystem {
public:
    map<pair<string, string>, vector<int>> avgTimes;
    map<int, pair<string, int>> checkIns;

    UndergroundSystem() {
        avgTimes.clear();
        checkIns.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> checkIn=checkIns[id];
        avgTimes[{checkIn.first, stationName}].push_back(t-checkIn.second);
        checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> times = avgTimes[{startStation, endStation}];
        double average = accumulate(times.begin(), times.end(), 0.0)/times.size();
        return average;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */