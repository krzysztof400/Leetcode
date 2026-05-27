class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> map;
        for(int i = 0; i<word.length(); ++i) {
            if (islower(word[i])){
                map[word[i]] = i;
            }
        }
        // for(const auto&[key, val] : map) {
        //     printf("key: %c, value: %d ", key, val);
        // }
        int count = 0;
        for(int i = 0; i<word.length(); ++i) {
            if(isupper(word[i]) && map.find(tolower(word[i])) != map.end()){
                if (map[tolower(word[i])] < i) {
                    // printf("\n%c, %d", word[i], i);
                    count++;
                }
                map[tolower(word[i])] = 200001;
            }
        }
        return count;
    }
};