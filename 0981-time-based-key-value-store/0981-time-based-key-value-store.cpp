class TimeMap {
private:
    unordered_map<string, map<int, string>> outerMap;
public:
    TimeMap() {   
    }
    
    void set(string key, string value, int timestamp) {
        outerMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) const {
        auto ts = outerMap.find(key);
        if(ts == outerMap.end()) return "";
        const auto& it = ts->second;
        auto s = it.upper_bound(timestamp);
        if(s == it.begin()) return "";
        return prev(s)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */