int X_O_R(int x){
    if(x%4==1){return 1;}
    if(x%4==2){return x+1;}
    if(x%4==3){return 0;}
    return x;
}

int MSB(int x){
    for(int i=61; i>=0; i--){
        int z= x & (1ll<<i);
        if(z){return i;}
    }
    return -1;
}

int A_N_D(int l, int r){
    int ans=l&r;
    int msb=MSB(r-l);
    if(msb!=-1){
        for(int i=0; i<=msb; i++){
            int z=ans;
            z^=(1ll<<i);
            if(z<ans){
                ans^=(1ll<<i);
            }
        }
    }
}


int O_R(int l, int r){
    int ans=(l|r);
    int msb=MSB(r-l);
    if(msb!=-1){
        for(int i=0; i<=msb; i++){
            ans|=(1ll<<i);
        }
    }
}