class Solution {
public:
    int romanToInt(string s) {
        size_t size = s.size();
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
        for (int i = 0; i<size; i++) {
            int current = map[s[i]];
            int next;
            if(i == size){
                next = 1;
            }
            else {
                next = map[s[i+1]];
            }
            if(current >= next) {
                sign = 1;
            }
            else {
                sign = -1;
            }
            sum += current*sign;
        }
        return sum;
    }
};