class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(int i = 0; i<ransomNote.length(); i++){
            char value = ransomNote[i];
            char key;
            for(int j = 0; j<magazine.length(); j++){
                key = magazine[j];
                if(key == value){
                    magazine[j] = '\0';
                    break;
                }
                if(j==magazine.length()-1){
                    return false;
                }
            }
        }
        return true;
    }
};