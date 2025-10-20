//2D prefix sum

void grid_sum(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cnt[i][j]+=(cnt[i][j-1]+cnt[i-1][j]-cnt[i-1][j-1]);
        }
    }
}