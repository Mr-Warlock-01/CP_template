
const int N=1e6+7;
vector<int>prime;
int spf[N];
int seq[N];

//  gen all prime and spf from 1 to N
//  add inline mod in Miller Rabin Primality Test (if needed)

inline ll add_mod(ll x, ll y, ll m){
    return (x += y) < m ? x : x - m;
}
inline ll mul_mod(ll x, ll y, ll m){
    ll res = __int128(x) * y % m;
    return res;
}
inline ll pow_mod(ll x, ll n, ll m) {
    ll res = 1 % m;
    for (; n; n >>= 1) {
      if (n & 1) res = mul_mod(res, x, m);
      x = mul_mod(x, x, m);
    }
    return res;
}

ll gcd(ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}

int pollard_rho(int n){
    while(1){
        int x=rnd()%n;
        int y=x; 
        int c=rnd()%n;
        int u=1, v, t=0;
        int *px = seq, *py = seq;

        while(1){
            *py++ = y = add_mod(mul_mod(y, y, n), c, n);
            *py++ = y = add_mod(mul_mod(y, y, n), c, n);
            if((x = *px++) == y){break;}
            v=u;
            u = mul_mod(u, abs(y - x), n);
            if(!u){return gcd(v, n);}
            if (++t == 32){
                t=0;
                if((u=gcd(u, n))>1 && u<n){return u;}
            }
        }
        if(t && (u=gcd(u, n))>1 && u<n){return u;}
    }
}

vector<int>factorize(int x){
    if(x==1){return vector <ll>();}
    if(prime_check(x)){return vector<ll>{x};}
    
    vector<int>v,w;

    while(x>1 && x<N){
        v.push_back(spf[x]);
        x/=spf[x];
    }

    if(x>=N){
      int pol=pollard_rho(x);
      v=factorize(pol);
      w=factorize(x/pol);
      v.insert(v.end(), all(w));
    }
    return v;
}