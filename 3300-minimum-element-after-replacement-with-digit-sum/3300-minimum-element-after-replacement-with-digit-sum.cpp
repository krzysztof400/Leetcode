class Solution {
public:
    int minElement(vector<int>& nums) {
        int minim = 100;
        int sum = 0;
        for(int& n : nums) {
            while(n>0){
                sum += n%10;
                n /= 10;
            }
            // n = sum;
            minim = min(minim, sum);
            sum =0;
        }
        return minim;
    }
};