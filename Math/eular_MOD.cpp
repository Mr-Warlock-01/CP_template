///Edular MOD 		////Edular MOD 		//Edular MOD  	

inline ll eular_MOD(ll x, ll m) {
    if(x<m){return x;}
    return (x%m)+m;
}

ll powMod(ll x, ll n, ll M) {
    ll res=eular_MOD(1, M);
    while(n){
        if(n&1){res=eular_MOD(res*x, M);}
        x=eular_MOD(x*x, M);
        n>>=1;
    }
    return res;
}