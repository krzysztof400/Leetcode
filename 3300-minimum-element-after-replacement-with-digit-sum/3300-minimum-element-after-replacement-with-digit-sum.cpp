class Solution {
public:
    int minElement(vector<int>& nums) {
        int8_t minim = 100;
        for(int n : nums) {
            int8_t sum = 0;
            while(n>0){
                sum += n%10;
                n /= 10;
            }
            // n = sum;
            if (sum<minim) {
                if(sum == 1) { return 1; }
                minim = sum;
            }
            sum =0;
        }
        return minim;
    }
};