class MedianFinder {
private:
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> bigger;
    bool odd = false;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smaller.size() == 0) {
            smaller.push(num);
            odd = true;
            return;
        }

        if(num<=smaller.top()) smaller.push(num);
        else bigger.push(num);

        if(smaller.size() > 1 + bigger.size()) {
            bigger.push(smaller.top());
            smaller.pop();
        } 
        else if (bigger.size() > smaller.size()) {
            smaller.push(bigger.top());
            bigger.pop();
        }

        odd = !odd;
    }
    
    double findMedian() {
        if(odd) {
            return smaller.top();
        }
        else {
            return ((double)bigger.top() + (double)smaller.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */