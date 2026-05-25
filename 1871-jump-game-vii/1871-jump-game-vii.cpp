class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int> canJump(n, 0);
        canJump[0] = 1;
        for(int i =1; i<n; ++i) {
            if (s[i] != '0') {
                continue;
            }
            for(int j = minJump; j<=maxJump && i-j >= 0; ++j) {
                if (canJump[i-j] == 1) {
                    canJump[i] = 1;
                    break;
                }
            }
        }
        // for(int j : canJump){
        //     printf("%d", j);
        // }
        return canJump[n-1] == 1;
    }
};