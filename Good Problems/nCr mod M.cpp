#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//using u128 = __uint128_t;

#define read()          freopen("folding.in","r",stdin)
#define write()         freopen("folding.out","w",stdout)

#define ff              first
#define ss              second
#define pb              push_back
#define endl            "\n"
#define ll              long long
#define double          long double
#define ull             unsigned long long
#define all(x)          x.begin(), x.end()
#define rall(x)         x.rbegin(), x.rend()
#define uniq(x)         unique(x.begin(), x.end()) - x.begin()
#define deci(x)         cout << fixed << setprecision(x);
#define war()           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const ll LLMax = 1e18;
const ll LLMin = -1e18;
//const ll MOD   = 1e9+7;
const double PI = acos(-1);       //3.1415926535897932384626

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};

//pbds
//template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//template<typename T>using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

//debug
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define db(x)
#endif

//sc
template<typename T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x : a) cin >> x; return cin; }

// nCr = n! / r! * (n-r)!
// nPr = n! / (n-r)!
// .order_of_key(x)
// *    .find_by_order(x)
//substr
//cin.ignore();
//__builtin_popcount()
//memset(dp, -1, sizeof(dp));
//cout<<"Case "<<T<<": ";


#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE


ll powMod(ll x, ll n){ll res=1; while(n){if(n&1){res=(res*x);} x=(x*x); n>>=1;} return res;}
ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}


#define int ll

vector<pair<int,int>>factor;        //p^q
vector<pair<int,int>>crt_vector;    //a1,m1
int factorial[50];                  //max factor cal[]

//CRT
ll educidean_algo(ll a, ll b, ll &x, ll &y){
    if(b==0){x=1; y=0; return a;}
    ll x1,y1;
    ll d=educidean_algo(b, a%b, x1,y1);
    x=y1;
    y=x1 -((a/b)*y1);
    return d;
}

ll invMod_p_q(ll a, ll m){
    ll x,y;
    educidean_algo(a,m,x,y);
    return (x+m)%m;
}

pair<ll,ll>CRT(ll a1, ll m1, ll a2, ll m2){
    ll n1, n2, ansM= m1*m2;
    educidean_algo(m1, m2, n1, n2);
    ll res=( ((((a1*n2)%ansM)*m2)%ansM) + ((((a2*n1)%ansM)*m1)%ansM) + ansM) % ansM;
    return {res, ansM};
}

//factor_calculation
void factorize(int M){
    if(M%2==0){
        int cnt=0;
        while(M%2==0){cnt++; M/=2;}
        factor.pb({2,cnt});
    }

    for(int i=3; (i*i)<=M; i+=2){
        int cnt=0;
        while(M%i==0){M/=i; cnt++;}
        if(cnt){factor.pb({i, cnt});}
    }
    if(M>1){factor.pb({M,1});}
}

void gen_factorial(int p, int mod){
    factorial[0]=1;
    for(int i=1; i<mod; i++){
        if(i%p!=0){factorial[i]=(factorial[i-1]*i)%mod;}
        else{factorial[i]=factorial[i-1]%mod;}
    }
}

ll trailing(ll x, ll p){
    ll res=0;
    while(x>0){x/=p; res+=x;}
    return res;
}

ll spf(ll x, ll p, ll mod){//O(log_p (x))
    ll res= powMod(factorial[mod-1], x/mod, mod);
    if(x>=p){res=(res*spf(x/p, p, mod))%mod;}
    res=(res*factorial[x%mod])%mod;
    return res;
}


ll C_mod_p_q(int n, int r, int p, int q){ //nCr mod p^q
    if((r>n) || (r<0)){return 0;}
    if((n==r) || (r==0)){return 1;}
    ll mod=powMod(p,q);
    int p_cnt=trailing(n,p) - trailing(r,p) - trailing(n-r, p);
    if(p_cnt>=q){return 0;}
    gen_factorial(p,mod);
    int up=spf(n,p,mod);
    int down=spf(r,p,mod) * spf(n-r,p,mod)%mod;
    int res=(up * invMod_p_q(down, mod))%mod;
    res=(res*powMod(p,p_cnt,mod))%mod;
    return res;
}

int nCr(int n, int r, int M){
    if((r>n) || (M==1) || (r<0)){return 0;}
    if((n==r) || (r==0)){return 1;}
    
    factorize(M);
    for(int i=0; i<factor.size(); i++){
        int a=C_mod_p_q(n,r,factor[i].ff, factor[i].ss);
        int m=powMod(factor[i].ff, factor[i].ss);
        crt_vector.pb({a,m});
    }

    //chineese Rem Throem
    pair<int,int>ans={crt_vector[0].ff,crt_vector[0].ss};
    for(int i=1; i<crt_vector.size(); i++){
        ans=CRT(ans.ff, ans.ss, crt_vector[i].ff, crt_vector[i].ss);
    }
    return ans.ff;
}

void clear_kori(){
    factor.clear();
    crt_vector.clear();
}

void solve(int T){
    int n,r;    cin>>n>>r;
    clear_kori();
    int ans=nCr(n,r,142857);
    cout<<ans<<endl;
}






//DRINK WATER
int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////

    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}
