///DSU       //DSU      //DSU       //DSU       //DSU       //DSU

int parent[N];
int dsu_size[N];

/*
void dsu_build(){
    for(int i=0; i<N; i++){
        parent[i]=i;
        dsu_size[i]=1;
    }
}
*/

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