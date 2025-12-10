int freq[N];
int div[N];
int g[N];
int exact[N];

void solve(int T){
    int n;  cin>>n;
    //frequency count
    for(int i=0; i<n; i++){
        int a;  cin>>a;
        freq[a]++;
    }
    //divisor count of every num
    for(int i=1; i<N; i++){
        for(int j=i; j<N; j+=i){
            div[i]+=freq[i];
        }
    }
    
    for(int i=1; i<N; i++){
        g[i]=(div[i]* (div[i]-1))/2;
    }

    int ans=0;
    for(int i=N-1; i>=1; i--){
        exact[i] = g[i];
        for(int j=i+i ;j<N ; j+=i){
            exact[i]-=exact[j];
        }
        ans+=(exact[i]*i);
    }
    cout<<ans<<endl;
} 