int Solution::isPalindrome(int A) {
    long int i = 1;
    int count = 0;
    while(A>i){
        i*=10;
        count++;
    }
    i = 1;
    for(int j = 0; j<count/2; j++){
        i*=10;
    }
    if(count%2){
        if(A%i==A/(i*10)) return 1;
        else return 0;
    }
    else{
        if(A%i==A/i) return 1;
        else return 0;
    }
}