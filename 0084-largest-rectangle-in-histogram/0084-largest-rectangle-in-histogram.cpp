class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        int res=0;
        vector<pair<int, int>> stack;
        stack.reserve(n);

        for(int i = 0; i<n; ++i) {
            int len = 0;
            while(!stack.empty() && stack.back().first >= nums[i]) {
                len += stack.back().second;
                int fld = len * stack.back().first;
                res = max(res, fld);
                stack.pop_back();
            }
            len += 1;
            res = max(res, nums[i]*len);
            if(!stack.empty()) {
                res = max(res, stack.back().first * (stack.back().second +1));
            }
            stack.emplace_back(nums[i], len);
        }

        int len = 0;
        while(!stack.empty()) {
            len += stack.back().second;
            int fld = len * stack.back().first;
            res = max(res, fld);
            stack.pop_back();
        }
        return res;
    }
};




// x - f'(x)/f(x)




        // for(int i =0; i<n; ++i) {
        //     int currMin = 100001;
        //     for(int j =i; j>=0; --j) {
        //         currMin = min(currMin, nums[j]);
        //         int field = currMin * (i-j+1);
        //         // cout << field << ", ";
        //         dp[i] = max(dp[i], field);
        //     }
        //     // cout << endl;
        // }