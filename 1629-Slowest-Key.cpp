class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int max_diffrence = releaseTimes[0];
        int chosen_one = 0;
        for(int i =1; i<releaseTimes.size(); i++){
            if(abs(releaseTimes[i]-releaseTimes[i-1]) > max_diffrence){
                max_diffrence = releaseTimes[i] - releaseTimes[i-1];
                chosen_one = i;
            }
            else if(abs(releaseTimes[i]-releaseTimes[i-1]) == max_diffrence && keysPressed[i]>keysPressed[chosen_one]){
                chosen_one = i;
            }
        }
        return keysPressed[chosen_one];
    }
};