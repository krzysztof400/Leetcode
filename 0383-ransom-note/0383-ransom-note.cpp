class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> umap;
        for(int i = 0; i<magazine.length(); i++){
            char m = magazine[i];
            int currentCount = umap[m];
            umap[m] = currentCount + 1;
        }

        for(int i = 0; i<ransomNote.length(); i++){
            char m = ransomNote[i];
            int currentCount = umap[m];
            if(currentCount == 0){
                return false;
            }
            umap[m] = currentCount - 1;
        }
        return true;
    }
};