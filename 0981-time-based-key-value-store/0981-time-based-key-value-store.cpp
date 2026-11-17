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
        auto underKey = outerMap.find(key);
        if(underKey == outerMap.end()) return "";
        const auto& timestamps = underKey->second;
        auto s = timestamps.upper_bound(timestamp);
        if(s == timestamps.begin()) return "";
        return prev(s)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */