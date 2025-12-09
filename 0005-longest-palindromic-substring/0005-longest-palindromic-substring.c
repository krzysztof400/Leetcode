char* longestPalindrome(char* s) {
    int expandAroundCenter(char *s, int left, int right) {
        int L = left, R = right;
        int n = strlen(s);
        
        while (L >= 0 && R < n && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
    
    if (s == NULL || strlen(s) == 0) {
        return "";
    }
    
    int start = 0, end = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int maxLen = (len1 > len2) ? len1 : len2;
        if (maxLen > (end - start)) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    int resultLen = end - start + 1;
    
    char* result = (char*)malloc(sizeof(char) * (resultLen + 1));

    strncpy(result, s + start, resultLen);
    
    result[resultLen] = '\0';

    return result;
}