class Solution {
public:
    int numberOfSpecialChars(string word) {
        // instead of hashmap well use array
        // intead of array well use bitmanipultion
        int lower = 0;
        int upper = 0;
        for(char ch : word) {
            if(islower(ch)) {
                lower |= (1 << (ch - 'a'));
                // lower |= (1 << 10);
            }
            else {
                upper |= (1 << (ch - 'A'));
            }
        }
        // printf("lower: %d", lower);
        return __builtin_popcountll(lower & upper);
    }
};