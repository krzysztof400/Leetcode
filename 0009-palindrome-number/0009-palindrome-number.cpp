class Solution {
public:
bool isPalindrome(int x) {
    if (x < 0){
        return false;
    }
    string number;
    number = to_string(x);
    int size = number.size();
    int p_left = size-1;
    int p_right = 0;

    while (p_left >= p_right) {
        if (number[p_left] != number[p_right]){
            return false;
        }
        p_left--;
        p_right++;
    }
    return true;
}
};