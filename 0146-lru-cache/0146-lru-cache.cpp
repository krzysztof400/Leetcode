class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> values;
    list<pair<int, int>> dll;
    int size;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        int val;
        if (values.find(key) == values.end()){
            return -1;
        }
        else {
            val= (*values[key]).first;
            dll.erase(values[key]);
        }
        dll.push_front({val, key});
        values[key] = dll.begin();
        return (*values[key]).first;
    }
    
    void put(int key, int value) {
        if (values.find(key) == values.end() && size == cap) {
            values.erase(dll.back().second);
            dll.pop_back();
        } 
        else if (values.find(key) != values.end()) {
            dll.erase(values[key]);
        }
        else { size++; }
        dll.push_front({value, key});
        values[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */