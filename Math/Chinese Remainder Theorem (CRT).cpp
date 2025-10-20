///CRT		//CRT		//CRT		//CRT		//CRT		//CRT

ll educidean_algo(ll a, ll b, ll &x, ll &y){
    if(b==0){x=1; y=0; return a;}
    ll x1,y1;
    ll d=educidean_algo(b, a%b, x1,y1);
    x=y1;
    y=x1 -((a/b)*y1);
    return d;
}

ll inv(ll a, ll m){
    ll x, y;
    ll g=educidean_algo(a, m, x, y);
    if(g==-1){return -1;}
    return (x+m)%m;
}

ll CRT(vector<pair<int,int>>&ar){
    ll x, y, res=0, M=1;
    for(int i =0; i<ar.size(); i++){M*=ar[i].ss;}
    for(int i =0; i<ar.size(); i++){
        x=M/ar[i].ss, y=inv(x, ar[i].ss);
        if(y==-1){return -1;}
        res=(res+(((x*ar[i].ff)%M)*y))%M;
    }
    return res;
}   //-1 = NO SOLUTION