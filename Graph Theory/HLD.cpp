//HLD

//LCS
int LCA[log_N][N];
int level[N];

//hld
int head[N];
int sub_child_sz[N];
int in[N];
int out[N];
int euler_arr[N];

int timer=0;

void dfs(int x, int par, int lev){
    level[x]=lev;
    LCA[0][x]=par;
    sub_child_sz[x]=1;
    for(auto &u: graph[x]){
        if(u==par){continue;}
        dfs(u, x, lev+1);
        sub_child_sz[x]+=sub_child_sz[u];
        if(sub_child_sz[u]>sub_child_sz[graph[x][0]]){
            swap(u, graph[x][0]);
        }
    }
}

void HLD_dfs(int x, int par){
    if(par==-1){head[x]=x;}
    in[x]=(++timer);
    euler_arr[timer]=arr[x];
    for(auto u:graph[x]){
        if(u==par){continue;}
        if(u==graph[x][0]){head[u]=head[x];} 
        else{head[u]=u;}
        HLD_dfs(u,x);
    }
    out[x]=timer;
}

int query_chain(int par,int u){
    int h=-1,res=0;
    while(h!=par){
        h=head[u];
        if(level[h]<level[par]){h=par;}
        res+=query(1,1,timer,in[h],in[u]);
        u=LCA[0][h];
    }
    return res;
}

int query_path(int u,int v){
    int par=find_lac(u,v);
    int res=query_chain(par,u)+query_chain(par,v);
    res-=query_chain(par,par);
    return res;
}

//build
//dfs(1,-1, 0);
//HLD_dfs(1, -1);
//lca_generate(n);
//build(1,1,timer);

//query
//query_path(u,v)