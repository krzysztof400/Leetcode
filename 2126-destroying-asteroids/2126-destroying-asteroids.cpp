class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for(const int& asteroid : asteroids) {
            if(mass < asteroid) {
                return false;
            }
            if(mass >= 100000){ return true; }
            mass += asteroid;
        }
        return true;
    }
};