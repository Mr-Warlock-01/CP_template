int arr[N];
pair<pair<int,int>,pair<int,int>>treee[4*N];    //{ans,sum},{left,right}

void build(int node, int st, int en){
    if(st==en){
        treee[node].ff.ff=arr[st];
        treee[node].ff.ss=arr[st];
        treee[node].ss.ff=arr[st];
        treee[node].ss.ss=arr[st];
        return;
    }
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node].ff.ff=max({treee[2*node].ff.ff, treee[2*node+1].ff.ff, treee[2*node].ss.ss+ treee[2*node+1].ss.ff});
    treee[node].ff.ss=treee[2*node].ff.ss+treee[2*node+1].ff.ss;
    treee[node].ss.ff=max(treee[2*node].ss.ff, treee[2*node].ff.ss+treee[2*node+1].ss.ff);
    treee[node].ss.ss=max(treee[2*node+1].ss.ss, treee[2*node+1].ff.ss+treee[2*node].ss.ss);
}

pair<pair<int,int>,pair<int,int>> query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return {{LLMin,0},{LLMin,LLMin}};}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    pair<pair<int,int>,pair<int,int>> q1= query(2*node, st, mid, l, r);
    pair<pair<int,int>,pair<int,int>> q2= query(2*node+1, mid+ 1, en, l, r);
    
    int ans=max({q1.ff.ff, q2.ff.ff, q1.ss.ss+q2.ss.ff});
    int sum=q1.ff.ss+q2.ff.ss;
    int left=max(q1.ss.ff, q1.ff.ss+q2.ss.ff);
    int right=max(q2.ss.ss, q2.ff.ss+q1.ss.ss);
    return {{ans,sum},{left,right}};
}


void update(int node, int st, int en, int ind, int val){
    if(st==en){ 
        treee[node].ff.ff=val;
        treee[node].ff.ss=val;
        treee[node].ss.ff=val;
        treee[node].ss.ss=val;
        return;
    }
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){update(2*node,st, mid, ind, val);}
    else{update(2*node+1, mid+1, en, ind, val);}
    treee[node].ff.ff=max({treee[2*node].ff.ff, treee[2*node+1].ff.ff, treee[2*node].ss.ss+ treee[2*node+1].ss.ff});
    treee[node].ff.ss=treee[2*node].ff.ss+treee[2*node+1].ff.ss;
    treee[node].ss.ff=max(treee[2*node].ss.ff, treee[2*node].ff.ss+treee[2*node+1].ss.ff);
    treee[node].ss.ss=max(treee[2*node+1].ss.ss, treee[2*node+1].ff.ss+treee[2*node].ss.ss);
    return;
}
