//Cycle Detection
bool cycle=0;
 
void cycle_check(int x){
    vis_cycle[x]=1;
    for(int u:graph[x]){
        if(vis_cycle[u]==1){cycle=1;}
        if(vis_cycle[u]==0){
            cycle_check(u);
        }
    }
    vis_cycle[x]=2;
}