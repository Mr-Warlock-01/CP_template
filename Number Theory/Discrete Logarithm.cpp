// Returns minimum x for which a ^ x % m = b % m.

ll gcd(ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}

int Discrete_Logarithm(int a, int b, int m) {
    a=a%m; b=b%m;
    int k=1, add=0, g;
    while((g=gcd(a, m))>1){
        if(b==k){return add;}
        if(b%g){return -1;}
        b/=g; m/=g; add++;
        k=((k*1ll*a)/g)%m;
    }

    int n=sqrt(m)+1;
    int an=1;
    for(int i=0; i<n; i++){an=(an*1ll*a)%m;}

    unordered_map<int,int>mpp;

    for(int q=0, cur=b; q<=n; q++){
        mpp[cur]=q;
        cur=(cur*1ll*a)%m;
    }

    for(int p=1, cur=k; p<=n; p++){
        cur=(cur*1ll*an)%m;
        if(mpp.count(cur)) {
            return (n*p)-mpp[cur]+add;
        }
    }
    return -1; //No soluition
}
