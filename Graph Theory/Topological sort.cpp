///Topological Sort         //Topological Sort          //Topological Sort          

vector<int>graph[N];
bool vis[N];

void dfs(int x){
    vis[x]=1;
    for(auto u:graph[x]){
        if(!vis[u]){
            dfs(u);
        }
    }
    st.push(x);
}

void topological_sort(){
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
}