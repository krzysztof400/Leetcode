class MedianFinder {
private:
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> bigger;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(smaller.empty() || num<=smaller.top()) {
            smaller.push(num);
        } 
        else bigger.push(num);

        if(smaller.size() > 1 + bigger.size()) {
            bigger.push(smaller.top());
            smaller.pop();
        } 
        else if (bigger.size() > smaller.size()) {
            smaller.push(bigger.top());
            bigger.pop();
        }
    }
    
    double findMedian() {
        if(smaller.size() > bigger.size()) {
            return smaller.top();
        }
        else {
            return (static_cast<double>(bigger.top()) + smaller.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */