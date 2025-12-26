class Solution {
public:
    int bestClosingTime(string customers) {
        size_t size = customers.size();
        vector<int>pen(size,0);
        if(customers[0]=='Y'){
            pen[0] = 1;
        }
        else {
            pen[0] = 0;
        }
        for(int i = 1; i< size; i++){
            if(customers[i]=='Y'){
                pen[i] = pen[i-1] + 1;
            }
            else {
                pen[i] = pen[i-1];
            }
        }
        pen.insert(pen.begin(),0);
        for (int& val : pen){
            printf("%d", val);
        }
        printf("\n");
        int totalY = pen[size];
        printf("%d\n", totalY);
        int min = 1000000;
        int min_idx = 0;
        for(int i =0; i<size+1; i++) {
            int lostC = i - pen[i];
            int lostY = totalY - pen[i];
            pen[i] = lostC + lostY;

            if(pen[i] < min){
                min = pen[i];
                min_idx = i;
            }
        }
        for (int& val : pen){
            printf("%d", val);
        }
        return min_idx;
    }
};