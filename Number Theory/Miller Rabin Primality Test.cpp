//Miller Rabin Primality Test
//use 128 if x>1e9
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}

bool is_composite(int x, int a, int d, int s){
    int z=powMod(a, d, x);
    if(z==1 || z==(x-1)){return 0;}
    for(int i=0; i<s; i++){
        z=(z*z)%x;
        if(z==(x-1)){return 0;}
    }
    return 1;
}
bool prime_check(int x){
    if(x<4){return 1;}
    int s=0;    //2^s;
    int d=x-1;
    while((d & 1)==0){d/=2; s++;}
    for(int i=0; i<5; i++){
        int a=2+(rnd()%(x-3));
        if(is_composite(x, a, d, s)){return 0;}
    }
    return 1;
}