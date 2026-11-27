class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m<n) return "";

        vector<int> inT(128,0);

        for(const char& c : t) {
            inT[c]++;
        }

        int left = 0;
        int right = 0;
        inT[s[0]]--;

        int corLef = 0;
        int corRig = INT_MAX;

        while(right < m && left < m) {
            if(isTin(inT)) {
                if(corRig - corLef >= right - left) {
                    corLef = left;
                    corRig = right;
                    if (right - left + 1 == n) break;
                }
                inT[s[left++]]++;
            }
            else {
                if(++right == m) break;
                inT[s[right]]--;
            }
        }
        if (corRig == INT_MAX) return "";
        return {s.begin()+corLef, s.begin()+corRig+1};
    }


    bool isTin(const vector<int>& inT) {
        for(int x : inT) {
            if(x > 0) return false;
        }
        return true;
    }
};