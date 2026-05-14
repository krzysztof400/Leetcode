class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        // check sum that appears max times

        // set that sum to the rest

        // PROBLEM: sometimes to set certain sum you have to change both nums sometimes just one, if sum >= limit we have sollution else

        // for sum x we have either 0 1 2 modifications of pair, trivial n^2 sollution

        // flipping: calc how pairs affect every sum
        int n = nums.size();
        vector<int> sums(2*limit +2);
        for(int i = 0; i<n/2; i++) {
            int a, b;
            if (nums[i] > nums[n-i-1]){
                a = nums[i];
                b = nums[n-i-1]; // symetry
            } else {
                a = nums[n-i-1];
                b = nums[i];
            }
            sums[1] += 2;
            sums[b+1] += -1;
            sums[a+b] += -1;
            sums[a+b+1] += 1;
            sums[a+limit+1] += 1;
        }
        for(int i = 1; i<2*limit+1; i++) {
            // printf("%d", sums[i]);
            sums[i] += sums[i-1];
        }
        // printf("\n");
        int mymin = sums[2];
        // printf("%d", mymin);
        for(int i =3; i<2*limit+1; i++) {
            // printf("%d", sums[i]);
            if (sums[i] < mymin) {
                mymin = sums[i];
            }
        }
        return mymin;
    }
};