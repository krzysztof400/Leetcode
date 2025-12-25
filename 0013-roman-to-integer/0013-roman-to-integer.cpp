class Solution {
public:
    int romanToInt(string s) {
        int size = s.size();
        unordered_map<char,int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int sign = 1;
        int sum = 0;
        int prev;
        for (int i = size; i>=0; i--) {
            int current = map[s[i]];
            if(current >= prev) {
                sign = 1;
            }
            else {
                sign = -1;
            }
            prev = current;
            sum += current*sign;
        }
        return sum;
    }
};