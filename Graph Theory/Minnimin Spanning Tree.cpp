///Min Spamming Tree            //Min Spamming Tree             //Min Spamming Tree

vector<pair<int,int>>graph[N];
pair<int,pair<int,int>>edge[N];

int parent[N];
int dsu_size[N];

int n,m;    


int find_set(int x){
    if(x==parent[x]){return x;}
    return parent[x]= find_set(parent[x]);
}

void union_sets(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(dsu_size[a]<dsu_size[b]){swap(a,b);}
    parent[b]=a;
    dsu_size[a]+=dsu_size[b];
}

void min_spanning_tree(){
    sort(edge, edge+m);
    for(int i=0; i<m; i++){
        if(find_set(edge[i].ss.ff)!= find_set(edge[i].ss.ss)){
            union_sets(edge[i].ss.ff,edge[i].ss.ss);
            graph[edge[i].ss.ff].pb({edge[i].ss.ss, edge[i].ff});
            graph[edge[i].ss.ss].pb({edge[i].ss.ff, edge[i].ff});
        }
    }
}


void clr(){
    for(int i=0; i<=(n+3); i++){
        graph[i].clear();
        parent[i]=i;
        dsu_size[i]=1;
    }
}