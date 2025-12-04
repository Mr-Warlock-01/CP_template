//Articulation Point
vector<int>graph[N];
bool visit[N];
bool point[N];      //1=articulation point, 0=not
int in_time[N];
int low_time[N];
int timer=0;

void articlar_point_check(int x, int p){
    visit[x]=1;
    in_time[x]=low_time[x]=(timer++);
    int child_count=0;
    for(int u:graph[x]){
        if(u==p){continue;}
        else if(visit[u]){
            low_time[x]=min(low_time[x], in_time[u]);
        }
        else{
            articlar_point_check(u, x);
            low_time[x]=min(low_time[x], low_time[u]);
            if((in_time[x]<=low_time[u]) && (p!=-1)){
                point[x]=1;
            }
            child_count++;
        }
    }
    if((child_count>1) && (p==-1)){
        point[x]=1;
    }
return;
}