int phi[N];
int ans[N];

void phi_1_to_N() {
    for (int i=0; i<N; i++){
        phi[i]=i;
    }
    for(int i=2; i<N; i++) {
        if(phi[i]==i) {
            for(int j=i; j<N; j+=i){
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}

void sum_of_gcd_all_pair_1_to_N(){
	phi_1_to_N();
	for(int i=1; i<N; i++){
        for(int j=2; i*j<N; j++){
            ans[i*j]+=i*phi[j];
        }
    }
    for(int i=2; i<N; i++){
    	ans[i]+=ans[i-1];
    }
}