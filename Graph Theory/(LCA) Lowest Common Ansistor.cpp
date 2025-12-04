//LCA
int LCA[log_N+1][N];
int level[N];

//initialize the whole LCA with -1 in start
void lca_generate(){  
    for(int i=1; i<log_N; i++){
        for(int j=0; j<N; j++){  //change here
            int x=LCA[i-1][j];
            if(x==-1){continue;}
            x=LCA[i-1][x];
            LCA[i][j]=x;
        }
    }
return;
}

int find_lac(int a, int b){
    if(level[a]>level[b]){swap(a,b);}
    int d=level[b]-level[a];
    while(d>0){
        int i=log2(d);
        b=LCA[i][b];
        d-=(1<<i);
    }
    if(a==b){return a;}
    for(int i=log_N-1; i>=0; i--){
        if((LCA[i][a]!=-1) && (LCA[i][a]!=LCA[i][b])){
            a=LCA[i][a];    b=LCA[i][b];
        }
    }
    return LCA[0][a];
}

int find_nth_parent(int x, int n){
    while(n>0){
        int z=log2(n);
        n-=(1<<z);
        x=LCA[z][x];
        if(x==-1){break;}
    }
    return x;
}