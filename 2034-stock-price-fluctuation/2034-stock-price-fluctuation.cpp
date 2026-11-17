class StockPrice {
private:
    unordered_map<int, int> timestampToPrice;
    multiset<int> prices;
    int latestTime = 0;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (timestampToPrice.find(timestamp) != timestampToPrice.end()) {
            int oldPrice = timestampToPrice.find(timestamp)->second;
            prices.erase(prices.find(oldPrice));
        }
        timestampToPrice[timestamp] = price;
        prices.insert(price);
        latestTime = max(latestTime, timestamp);
    }
    
    int current() {
        return timestampToPrice[latestTime];    
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */