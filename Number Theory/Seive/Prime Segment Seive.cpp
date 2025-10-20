///segment sieve         //segment sieve         //segment sieve         //segment sieve         //segment sieve

    int l,r;    cin>>l>>r;
    if(l==1){l++;}
    bool ans[r-l+1]={0};
    for(int i=0; i<v.size();i++){
        if((v[i]*v[i])<=r){
            int p=(l/v[i])*v[i];
            if(p<l){p+=v[i];}
            if(p==v[i]){p+=v[i];}
            for( ; p<=r; p+=v[i]){
                ans[p-l]=1;
            }
        }
        else{break;}
    }
    for(int i=0; i<(r-l+1); i++){
        if(ans[i]==0){cout<<i+l<<endl;}
    }