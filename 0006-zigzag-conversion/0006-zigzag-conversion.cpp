class Solution {
public:
    string convert(string s, int numRows) {
        size_t size = s.size();
        vector<char> result;
        int maxCol;
        if (numRows == 1){
            return s;
        }
        else{
            maxCol = ceil((float)(size+1)/(2*numRows-2));
        }
        printf("col: %d, size: %d", maxCol, size);
        for (int row = 0; row<numRows; row++) {
            for (int col = 0; col<maxCol; col++){
                int vertical = row + col*(2*numRows-2);
                if ( vertical < size){
                    result.push_back(s[vertical]);
                }
                if ( row != 0 && row != numRows-1){
                    int diagonal = vertical + 2*(numRows-row-1);
                    if( diagonal < size){
                        result.push_back(s[diagonal]);
                    }
                }
            }
        }
        string str(result.begin(), result.end());
        return str;
    }
};