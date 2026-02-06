//Hashing on Tree

//const int b1= 137;
//const int b2= 277;
//const int m1= 14457881;
//const int m2= 11457857;
const ll b1= 1949313259;  
const ll b2= 1997293877;  
const ll m1= 2091573227;
const ll m2= 2117566807;

const int N=1e5+7;

ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}

ll base[2][N];

void pre_cal(){
    base[0][0]=base[1][0]=1;
    for(int i=1; i<N; i++){
        base[0][i]=(base[0][i-1]*b1)%m1;
        base[1][i]=(base[1][i-1]*b2)%m2;
    }
}

struct TreeHash{
    int n;
    vector<vector<int>>graph;
    vector<pair<ll,ll>>hash;
    vector<int>sub_tree_sz;

    TreeHash(int _n):n(_n){
        graph.assign(n+1, {});
        hash.assign(n+1, {0, 0});
        sub_tree_sz.assign(n+1, 0);
    }

    pair<ll,ll>hash_dfs(int x, int par, int lev){
        ll ans1=0, ans2=0, sz=1;
        for(int u:graph[x]){
            if(u==par){continue;}
            pair<int,int>child=hash_dfs(u,x,lev+1);
            ans1=(ans1+child.ff)%m1;
            ans2=(ans2+child.ss)%m2;
            sz+=sub_tree_sz[u];
        }
        sub_tree_sz[x]=sz;
        ll z1=(sz*base[0][lev])%m1;
        ll z2=(sz*base[1][lev])%m2;
        ans1=powMod(z1,ans1,m1);
        ans2=powMod(z2,ans2,m2);
        return hash[x]={ans1,ans2};
    }

    void addEdge(int u, int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
};

//TreeHash t1(n);
//t1.addEdge(u, v);
//t1.hash_dfs(node, -1, 1);