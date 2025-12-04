//lazy tree
int arr[N];
int treee[4*N];
int lazy[4*N];

void lazy_build(int node, int st, int en){   //same as normal segment tree
    if(st==en){  treee[node] = arr[st]; return;}
    int mid=((en-st)/2)+st;
    lazy_build(2*node, st, mid);
    lazy_build(2*node+1, mid+1, en);
    treee[node]=treee[2*node]+treee[2*node+1];
    return;
}

void relax(int node, int st, int en){
    if(lazy[node]!=0){
        treee[node]+=((en-st+1)*lazy[node]);
        if(st!=en){ lazy[2*node]+=lazy[node];   lazy[2*node+1]+=lazy[node];}
        lazy[node]=0;
    }
}

int lazy_query(int node, int st, int en, int l, int r){
    relax(node, st, en);
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    int q1= lazy_query(2*node, st, mid, l, r);
    int q2= lazy_query(2*node+1, mid+ 1, en, l, r);
    return q1+q2;
}

void lazy_update(int node, int st, int en, int l, int r, int val){
    relax(node, st, en);
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        treee[node]+=((en-st+1)*val);
        if(st!=en){ lazy[2*node]+=val;   lazy[2*node+1]+=val;}
        return;
    }
    int mid=((en-st)/2)+st;
    lazy_update(2*node, st, mid, l, r, val);
    lazy_update(2*node+1, mid+1, en, l, r, val);
    treee[node]=treee[2*node] + treee[2*node+1];
    return;
}