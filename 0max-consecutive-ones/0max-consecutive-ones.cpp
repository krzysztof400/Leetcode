class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0;
        int best = 0;
        for (int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                counter++;
            }
            else{
                if(counter>=best){
                    best = counter;
                }
                counter = 0;
            }
        }
        if(counter>=best){
                    best = counter;
        }
        return best;
    }
};