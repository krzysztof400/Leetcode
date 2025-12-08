int countTriples(int n) {
    int squareIsInteger(int num){
        int sqrtN = (int)sqrt(num);
        return (sqrtN * sqrtN == num);
    }
    int count = 0;
    for(int i = 1; i < n; i++){
        for(int j = i; j < n; j++){
            int c = i*i + j*j;
            if(squareIsInteger(c) && sqrt(c) <= n){
                count++;
            }
        }
    }
    return 2*count;
}