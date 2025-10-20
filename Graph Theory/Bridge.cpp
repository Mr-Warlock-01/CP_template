///Bridge           //Bridge            //Bridge            //Bridge

vector<int>graph[N];
bool vis[N];
int in[N];
int low[N];

vector<pair<int,int>>ans;       // bridges (u,v);

int timer=0;

void bridge_find(int x, int p){
    vis[x]=1;
    in[x]=low[x]=(timer++);
    for(int i=0; i<graph[x].size(); i++){
        if(graph[x][i]==p){continue;}
        else if(vis[graph[x][i]]){
            low[x]=min(low[x], in[graph[x][i]]);
        }
        else{
            bridge_find(graph[x][i], x);
            low[x]=min(low[x], low[graph[x][i]]);
            if(low[graph[x][i]]>in[x]){
                int u=x;
                int v=graph[x][i];
                ans.pb({u,v});
            }
        }
    }
return;
}


