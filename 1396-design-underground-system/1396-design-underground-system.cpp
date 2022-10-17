class UndergroundSystem {
public:
    unordered_map<int,vector<pair<string,int>>> mb;
    unordered_map<string,pair<int,int>> sd;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mb[id].push_back({stationName,t});
    }
    
    void checkOut(int id, string stationName, int t) {
        sd[(mb[id].back().first+"to"+stationName)] = {sd[(mb[id].back().first+"to"+stationName)].first+t-mb[id].back().second,sd[(mb[id].back().first+"to"+stationName)].second+1};
        mb[id].pop_back();
    }
    
    double getAverageTime(string startStation, string endStation) {
        double m = (double)(sd[(startStation+"to"+endStation)].first)/sd[(startStation+"to"+endStation)].second;
        return m;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */