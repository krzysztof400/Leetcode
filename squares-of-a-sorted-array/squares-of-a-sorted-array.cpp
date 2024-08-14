class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n);
        int left = 0;
        int right = n-1;
        int pos = n-1;
        
        while(right>=left){
            int squaredLeft = nums[left]*nums[left];
            int squaredRight = nums[right]*nums[right];
            
            if(squaredLeft>squaredRight){
                newNums[pos] = squaredLeft;
                left++;
            }
            else{
                newNums[pos] = squaredRight;
                right--;
            }
            pos--;
        }
        return newNums;
    }
};