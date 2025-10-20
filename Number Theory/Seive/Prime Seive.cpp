///Prime Seive          //Prime Seive           //Prime Seive

const int N=1e7+2;
vector<int>prime;
 
void prime_gen(){
    bitset<N>p;
    p.set();
    p[0]=p[1]=0;
    prime.pb(2);
    
    ll i=3;
    for(; (i*i)<N; i+=2){
        if(p[i]==1){
            prime.pb(i);
            for(ll j=i*i; j<N; j+=(2*i)){p[j]=0;}
        }
    }
    for(; i<N; i+=2){
        if(p[i]==1){
            prime.pb(i);
        }
    }

}