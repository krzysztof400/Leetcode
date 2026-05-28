class Trie {
public:
    vector<array<int, 26>> trie;
    vector<int> best_idx;
    const vector<string>& container; 

    Trie(const vector<string>& words) : container(words) {
        trie.push_back({});
        
        int best_overall = 0;
        for (int j = 1; j < words.size(); ++j) {
            if (words[j].length() < words[best_overall].length()) {
                best_overall = j;
            }
        }
        best_idx.push_back(best_overall);

        for (int j = 0; j < words.size(); ++j) {
            const string& w = words[j];
            int curr = 0;
            
            for (int i = w.length() - 1; i >= 0; --i) {
                int char_idx = w[i] - 'a';
                
                if (trie[curr][char_idx] == 0) {
                    trie.push_back({});
                    trie[curr][char_idx] = trie.size() - 1;
                    best_idx.push_back(j);
                }
                
                curr = trie[curr][char_idx];

                int current_best = best_idx[curr];
                if (container[j].length() < container[current_best].length() || 
                   (container[j].length() == container[current_best].length() && j < current_best)) {
                    best_idx[curr] = j;
                }
            }
        }
    }

    int search(const string& w) {
        int curr = 0;
        for (int i = w.length() - 1; i >= 0; --i) {
            int char_idx = w[i] - 'a';
            
            if (trie[curr][char_idx] == 0) {
                break;
            }
            curr = trie[curr][char_idx];
        }
        return best_idx[curr];
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie t(wordsContainer);

        vector<int> result;
        result.reserve(wordsQuery.size());

        for (const string& q : wordsQuery) {
            result.push_back(t.search(q));
        }
        
        return result;
    }
};