//Hashing on Tree

//const int b1= 137;
//const int b2= 277;
//const int m1= 14457881;
//const int m2= 11457857;
//const ll b1= 1949313259;  
//const ll b2= 1997293877;  
//const ll m1= 2091573227;
//const ll m2= 2117566807;

ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}

vector<ll>graph[N]; 
ll hash[N]; 
ll sub_tree_sz[N];
                               //p=1 initially as power---->level of tree
ll hash_dfs(ll x, ll par, ll base, ll p, ll mod){        //base,power,mod
    ll ans=0, sz=1;
    for(int i=0; i<graph[x].size(); i++){
        if(graph[x][i]!=par){
            ans=(ans+ hash_dfs(graph[x][i], x, (base*p)%mod, p+1, mod))%mod;        //if needed pass new base as
            sz+=sub_tree_sz[graph[x][i]];                                           //    --->powMod(base,p,mod)
        }
    }
    sub_tree_sz[x]=sz;
    ll z=(sz*base)%mod;
    ans=powMod(z,ans,mod);
    return hash[x]=ans;
}