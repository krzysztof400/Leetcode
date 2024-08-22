class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        int count = 0;

        for(int i = 0; i < size; i++) {
            if(arr[i] == 0) {
                count++;
            }
        }

        int i = size - 1;
        int j = size + count - 1;
        while (i < j) {
            if (j < size) {
                arr[j] = arr[i];
            }
            if (arr[i] == 0) {
                j--;
                if (j < size) {
                    arr[j] = 0;
                }
            }
            i--;
            j--;
        }
    }
};
