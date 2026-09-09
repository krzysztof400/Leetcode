class Solution {
public:
    long long countCommas(long long n) {
        if (n<1000) {
            return 0;
        }
        int loga = log10l(n);
        cout << loga << endl;
        long long sum = 0;
        for(int i=3; i<loga; i++) {
            sum += pow(10,i) * 9 * (i/3);
        }
        sum += (n - pow(10, loga) + 1) * (loga/3);
        return sum;
    }
};
