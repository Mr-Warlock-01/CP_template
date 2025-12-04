int sumOfDigits(int n){
    if(n<=0){return 0;}
    int res=0;
    for(int p=1; p<=n; p*=10){
        int pp10= p*10;
        int high= n/pp10;
        int cur = (n/p)%10;
        int low = n%p;
        res += (high*p*45) + (((cur*(cur-1))/2)*p) + (cur*(low+1));
    }
    return res;
}