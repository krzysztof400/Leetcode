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

        // smaller = {1, 2}
        // bigger = {3}

        // odd = true
        
        // smaller.push(num);

        if(num<=smaller.top()) smaller.push(num);
        else bigger.push(num);

        // printf("small: %d, big: %d\n", smaller.size(), bigger.size());
        if(smaller.size() > 1 + bigger.size()) {
            bigger.push(smaller.top());
            smaller.pop();
        } 
        else if (bigger.size() > smaller.size()) {
            // printf("move to smaller trig");
            smaller.push(bigger.top());
            bigger.pop();
        }
        // printf("small: %d, big: %d\n", smaller.size(), bigger.size());

        odd = !odd;
        // print();
    }
    
    double findMedian() {
        if(odd) {
            // printf("hi");
            return smaller.top();
        }
        else {
            return ((double)bigger.top() + (double)smaller.top()) / 2;
        }
    }

    // void print() {
    //     cout << "smaller:" << smaller.top() << endl;
    //     cout << "bigger:" << bigger.top() << endl;
    //     if (odd) cout << "is odd?" <<  "yes" << endl;
    //     else cout << "is odd?" <<  "no" << endl;
    //     cout << endl;
    // }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */