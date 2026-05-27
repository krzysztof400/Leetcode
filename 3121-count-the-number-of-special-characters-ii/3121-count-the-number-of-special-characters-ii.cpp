class Solution {
public:
    int numberOfSpecialChars(string word) {
        int map[26] = {0}; // 1 - found lowercase, wasnt upper case before 2 - found uppercase after lowercase 3 - found lowercase after first uppercase
        for(char c : word) {
            // if (map[c - 'a'] == 3){
            //     continue;
            // }
            if (islower(c)) {
                if(map[c - 'a'] == 2 || map[c - 'a'] == 3) {
                    map[c - 'a'] = 3;
                }
                else {
                    map[c - 'a'] = 1;
                }
            } 
            else {
                if (map[c - 'A'] == 1 || map[c - 'A'] == 2) {
                    map[c - 'A'] = 2;
                }
                else {
                    map[c - 'A'] = 3;
                }
            }

        }
        // for(const auto&[key, val] : map) {
        //     printf("key: %c, value: %d ", key, val);
        // }
        int count = 0;
        // for(int i = 0; i<word.length(); ++i) {
        //     char c = word[i];
        //     if(isupper(c) && map.find(tolower(c)) != map.end()){
        //         if (map[tolower(word[i])] < i) {
        //             // printf("\n%c, %d", word[i], i);
        //             count++;
        //         }
        //         map[tolower(c)] = 200001;
        //     }
        // }
        for(int i : map) {
            if(i == 2) { count++; }
        }
        return count;
    }
};