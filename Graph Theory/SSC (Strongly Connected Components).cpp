///SSC			//SSC 			//SSC 			//SSC 


vector<int>graph[N];
vector<int>rev_graph[N];
bool vis[N];
int parent[N];
stack<int>st;
vector<int>new_graph[N];


void dfs(int x){
    vis[x]=1;
    for(auto u:graph[x]){
        if(!vis[u]){
            dfs(u);
        }
    }
    st.push(x);
}

void topological_sort(){   //call
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void ssc_dfs(int x, int p){
    vis[x]=1;
    parent[x]=p;
    for(auto u:rev_graph[x]){
        if(!vis[u]){
            ssc_dfs(u,p);
        }
    }
}

void SSC(){     //call
    while(!st.empty()){
        int p=st.top();
        st.pop();
        if(!vis[p]){
            ssc_dfs(p, p);
        }
    }
}

void build_new_graph(){
    for(int i=1; i<=n; i++){
        if(parent[edge[i].ff]!=parent[edge[i].ss]){
            new_graph[edge[i].ff].pb(parent[edge[i].ss]);
        }
    }
}




////////////////////////////////
    topological_sort();
    for(int i=0; i<=n+3; i++){vis[i]=0;}
    SSC();




	for(int i=1; i<=n; i++){	//directed graph
        int u,v;	cin>>u>>v;
        graph[u].pb(v);
        rev_graph[v].pb(u);
    }