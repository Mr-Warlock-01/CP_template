///2D lazy tree         //2D lazy tree          //2D lazy tree      //2D lazy tree

const int N_MAX=4*52;    //4*node_need

struct segtree_y {
    int tree[N_MAX];
    int lazy[N_MAX];
    int NN;

    int query(int node, int st, int en, int i, int j){
        if(st>j || en<i){return 0;}
        if(st>=i && en<=j){
            return (lazy[node]*(en-st+1))+tree[node];
        } 
        int mid=(st+en)>>1;
        int lc=2*node;
        int rc=lc+1; 
        return query(lc, st, mid, i, j) + query(rc, mid + 1, en, i, j) 
             + (lazy[node] * (min(en,j) - max(st, i) + 1));
    }

    void update(int node, int st, int en, int i, int j, int val){
        if(st>j || en<i){return;}
        if(st>=i && en<=j){
            lazy[node]+=val;
            return;
        }
        int mid=(st+en)>>1;
        int lc=2*node;
        int rc=lc+1;  
        update(lc, st, mid, i, j, val);
        update(rc, mid + 1, en, i, j, val);
        tree[node] += (min(en, j) - max(i, st) + 1) * val;
    }

    void init(int n){
        NN = n;
        memset(lazy, 0, sizeof(lazy));
        memset(tree, 0, sizeof(tree));
    }

    int query(int i, int j){
        return query(1, 0, NN-1, i, j);
    }

    void update(int i, int j, int val){
        update(1, 0, NN-1, i, j, val);
    }
};

struct segtree_x {
    segtree_y tree[N_MAX];
    segtree_y lazy[N_MAX];
    int NN;

    void init(int node, int st, int en){
        lazy[node].init(NN);
        tree[node].init(NN);
        if(st == en) return;
        int mid=(st+en)>>1;
        int lc=2*node;
        int rc=lc+1;  
        init(lc, st, mid); 
        init(rc, mid + 1, en);
    }

    int query(int node, int st, int en, int i, int j, int b1, int b2){
        if(st>j || en<i){return 0;}
        if(st>=i && en<=j){
            return tree[node].query(b1, b2)+ (lazy[node].query(b1, b2)*(en-st+1));
        }
        int mid=(st+en)>>1;
        int lc=2*node;
        int rc=lc+1;  
        return query(lc, st, mid, i, j, b1, b2) 
             + query(rc, mid+1, en, i, j, b1, b2) 
             + (lazy[node].query(b1, b2) * (min(j, en) - max(st, i) + 1));
    }

    void update(int node, int st, int en, int i, int j, int b1, int b2, int val){
        if(st>j || en<i){return;}
        if(st>=i && en<=j){
            lazy[node].update(b1, b2, val);
            return;
        }
        int mid=(st+en)>>1;
        int lc=2*node;
        int rc=lc+1; 
        update(lc, st, mid, i, j, b1, b2, val);
        update(rc, mid+1, en, i, j, b1, b2, val);
        tree[node].update(b1, b2, val * (min(j,en)-max(i,st)+1));
    }

    void init(int n){
        NN=n;
        init(1, 0, NN - 1);
    }

    void update(int a1, int b1, int a2, int b2, int val){
        update(1, 0, NN-1, a1, a2, b1, b2, val);
    }

    int query(int a1, int b1, int a2, int b2){
        return query(1, 0, NN-1, a1, a2, b1, b2);
    }
};


//in main function
    //segtree_x tree;
    //tree.init(n+1);
