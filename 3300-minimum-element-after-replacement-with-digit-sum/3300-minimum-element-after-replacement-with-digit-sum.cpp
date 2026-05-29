class Solution {
public:
    int minElement(vector<int>& nums) {
        int minim = 100;
        for(int n : nums) {
            int sum = 0;
            while(n>0){
                sum += n%10;
                n /= 10;
            }
            if(sum == 1) { return 1; }
            // n = sum;
            if (sum<minim) {
                minim = sum;
            }
            sum =0;
        }
        return minim;
    }
};