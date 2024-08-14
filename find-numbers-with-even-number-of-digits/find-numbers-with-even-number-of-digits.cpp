class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int counter = 0;
        for(int i = 0; i<nums.size(); i++){
            int numDigits = floor(log10(nums[i]))+1;
            if(numDigits%2 == 0){
                counter++;
            }
        }
        return counter;
    }
};