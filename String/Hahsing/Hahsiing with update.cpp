const int N=1e5+7;

const int B1= 137;
const int B2= 277;
const int M1= 14457881;
const int M2= 11457857;

struct node{
    int l_hash1, l_hash2, r_hash1, r_hash2;
}tree[4*N];

int diablo[4*N];
int b1p[N],b2p[N];
string s;

void pre_cal(int n){
    b1p[0]=b2p[0]=1;
    for(int i=1; i<n; i++){
        b1p[i]=(b1p[i-1]*B1)%M1;
        b2p[i]=(b2p[i-1]*B2)%M2;
    }
}

void build(int node, int st, int en){
    if(st==en){
        tree[node].l_hash1=s[st]-'a'+1;
        tree[node].r_hash1=s[st]-'a'+1;
        tree[node].l_hash2=s[st]-'a'+1;
        tree[node].r_hash2=s[st]-'a'+1;
        diablo[node]=1;
        return;
    }
    int L=2*node; int R=L+1;
    int mid=((en-st)/2)+st;
    build(L, st, mid);
    build(R, mid+1, en);
    tree[node].l_hash1=(tree[L].l_hash1+((tree[R].l_hash1*b1p[diablo[L]])%M1))%M1;
    tree[node].r_hash1=(tree[R].r_hash1+((tree[L].r_hash1*b1p[diablo[R]])%M1))%M1;
    tree[node].l_hash2=(tree[L].l_hash2+((tree[R].l_hash2*b2p[diablo[L]])%M2))%M2;
    tree[node].r_hash2=(tree[R].r_hash2+((tree[L].r_hash2*b2p[diablo[R]])%M2))%M2;
    diablo[node]=diablo[L]+diablo[R];
    return;
}

int get_idx(int node, int st, int en ,int idx){
    if(st==en){return st;}
    int mid=(st+en)/2;
    int L=2*node; int R=L+1;
    if(idx<=diablo[L]){return get_idx(L, st, mid, idx);}
    else{return get_idx(R, mid+1, en, idx- diablo[L]);}
}

void update(int node, int st, int en, int ind, char c){
    if(st==en){ 
        tree[node].l_hash1=c-'a'+1;
        tree[node].r_hash1=c-'a'+1;
        tree[node].l_hash2=c-'a'+1;
        tree[node].r_hash2=c-'a'+1;
        diablo[node]=1;
        return;
    }
    int mid=((en-st)/2)+st;
    int L=2*node; int R=L+1;
    if(ind<=mid){update(L,st, mid, ind, c);}
    else{update(R, mid+1, en, ind, c);}
    tree[node].l_hash1=(tree[L].l_hash1+((tree[R].l_hash1*b1p[diablo[L]])%M1))%M1;
    tree[node].r_hash1=(tree[R].r_hash1+((tree[L].r_hash1*b1p[diablo[R]])%M1))%M1;
    tree[node].l_hash2=(tree[L].l_hash2+((tree[R].l_hash2*b2p[diablo[L]])%M2))%M2;
    tree[node].r_hash2=(tree[R].r_hash2+((tree[L].r_hash2*b2p[diablo[R]])%M2))%M2;
    diablo[node]=diablo[L]+diablo[R];
    return;
}

void erase_node(int node, int st, int en, int ind){
    if(st==en){ 
        tree[node].l_hash1=0;
        tree[node].r_hash1=0;
        tree[node].l_hash2=0;
        tree[node].r_hash2=0;
        diablo[node]=0;
        return;
    }
    int mid=((en-st)/2)+st;
    int L=2*node; int R=L+1;
    if(ind<=mid){erase_node(L,st, mid, ind);}
    else{erase_node(R, mid+1, en, ind);}
    tree[node].l_hash1=(tree[L].l_hash1+((tree[R].l_hash1*b1p[diablo[L]])%M1))%M1;
    tree[node].r_hash1=(tree[R].r_hash1+((tree[L].r_hash1*b1p[diablo[R]])%M1))%M1;
    tree[node].l_hash2=(tree[L].l_hash2+((tree[R].l_hash2*b2p[diablo[L]])%M2))%M2;
    tree[node].r_hash2=(tree[R].r_hash2+((tree[L].r_hash2*b2p[diablo[R]])%M2))%M2;
    diablo[node]=diablo[L]+diablo[R];
    return;
}

//lh1, lh2, rh1, rh2, sz
// 0    1    2    3   4
tuple<int,int,int,int,int>query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return {0,0,0,0,0};}
    else if(st>=l && en<=r){return {tree[node].l_hash1, tree[node].l_hash2, tree[node].r_hash1, tree[node].r_hash2, diablo[node]};}
    int mid=((en-st)/2)+st;
    int L=2*node; int R=L+1;
    auto q1=query(L,st, mid, l, r);
    auto q2=query(R,mid+1, en, l, r);

    int lh1=(get<0>(q1)+((get<0>(q2)*b1p[get<4>(q1)])%M1))%M1;
    int rh1=(get<2>(q2)+((get<2>(q1)*b1p[get<4>(q2)])%M1))%M1;
    int lh2=(get<1>(q1)+((get<1>(q2)*b2p[get<4>(q1)])%M2))%M2;
    int rh2=(get<3>(q2)+((get<3>(q1)*b2p[get<4>(q2)])%M2))%M2;
    int sz=get<4>(q1)+get<4>(q2);
    return {lh1, lh2, rh1, rh2, sz};
}


//int main
    pre_cal(n+4);
    build(1 ,1, n);