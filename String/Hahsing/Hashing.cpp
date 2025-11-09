///HASHING          //HASHING           //HASHING           //HASHING           //HASHING          

int p1=137,  M1=14457881;
int p2=455,  M2=11457857;

ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll inv(ll x, ll M){return powMod(x, M-2, M);}

struct  Hashing{
    char arr[N];
    int hash_1[N];
    int hash_2[N];
    int inv1[N];
    int inv2[N];
    int n;

    Hashing(int n): n(n){}

    void build_hash(){
        int pp1=1;
        int pp2=1;
        hash_1[0]=hash_2[0]=0;
        for(int i=1; i<=n; i++){
           hash_1[i]=(hash_1[i-1]+((arr[i]*pp1)%M1))%M1;
           hash_2[i]=(hash_2[i-1]+((arr[i]*pp2)%M2))%M2;
           pp1=(pp1*p1)%M1;
           pp2=(pp2*p2)%M2;
        }
        inv1[n]=inv(powMod(p1,n,M1), M1);
        inv2[n]=inv(powMod(p2,n,M2), M2);
        for(int i=n-1; i>=0; i--){
            inv1[i]=(inv1[i+1]*p1)%M1;
            inv2[i]=(inv2[i+1]*p2)%M2;
        }
    }

    pair<int,int>find_hash(int l, int r){
        int h_1=(hash_1[r]-hash_1[l-1])%M1;
        h_1=(h_1+M1)%M1;    
        h_1=(h_1 * inv1[l])%M1;
        int h_2=(hash_2[r]-hash_2[l-1])%M2;
        h_2=(h_2+M2)%M2;    
        h_2=(h_2 * inv2[l])%M2;
        return {h_1,h_2};
    }
};


void solve(int T){
    int n;  cin>>n;
    string s;   cin>>s;
    string t;   cin>>t;
    s="#"+s;
    t="#"+t;
    Hashing *sss=new Hashing(n);
    Hashing *ttt=new Hashing(n);

    for(int i=1; i<=n; i++){
        sss->arr[i]=s[i];
        ttt->arr[i]=t[i];
    }

    sss->build_hash();
    ttt->build_hash();

    int ans=0;

    for(int i=1; i<=n; i++){
        int idx=i-1;
        int l=i, r=n;
        while(l<=r){
            int mid=(l+r)/2;
            pair<int,int> q1=sss->find_hash(i,mid);
            pair<int,int> q2=ttt->find_hash(i,mid);
            if(q1==q2){
                idx=mid; l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(idx==n){continue;}
        else{
            if(s[idx+1]<t[idx+1]){
                ans+=(n-idx);
            }
        }
    }
    cout<<ans<<endl;

}   


    

int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////
   
    /////////////////////////////////////
    int tc=1;
    //cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
} 

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/  