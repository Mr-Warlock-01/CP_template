//segment sieve

const int N=1e12+1;    //max R
const int NN=1e6+1;  //sqrt(N)+1;
vector<int>prime_gen(){
    bitset<NN>p;
    p.set();
    p[0]=p[1]=0;
    vector<int>pri;
    pri.pb(2);
    ll i=3;
    for(; (i*i)<NN; i+=2){
        if(p[i]==1){
            pri.pb(i);
            for(ll j=i*i; j<NN; j+=(2*i)){p[j]=0; }
        }
    }
    for(; i<NN; i+=2){
        if(p[i]==1){
            pri.pb(i);
        }
    }
    return pri;
}

vector<int>prime;

void prime_seg_seive(int l, int r){
    vector<int>vv=prime_gen();
    if(l==1){l++;}
    bool ans[r-l+1]={0};
    for(int i=0; i<vv.size();i++){
        if((vv[i]*vv[i])<=r){
            int p=(l/vv[i])*vv[i];
            if(p<l){p+=vv[i];}
            if(p==vv[i]){p+=vv[i];}
            for( ; p<=r; p+=vv[i]){
                ans[p-l]=1;
            }
        }
        else{break;}
    }
    for(int i=0; i<(r-l+1); i++){
        if(ans[i]==0){
            prime.pb(i+l);
        }
    }
}