class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;

        while (s[n] == ' ') { --n; }

        int count = 0;
        cout << n;
        for(n; s[n] != ' ' && n >= 0; --n) { ++count; }
        return count;
    }
};