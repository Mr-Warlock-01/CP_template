//2D segment tree
//only call x

int arr[N][N];
int tree[4*N][4*N];
int m;
void build_y(int node_x, int st_x, int en_x, int node_y, int st_y, int en_y){
    if(st_x==en_x && st_y==en_y){
        tree[node_x][node_y]=arr[st_x][st_y];
        return;
    }
    if(st_y==en_y){
        tree[node_x][node_y] = tree[2*node_x][node_y] + tree[2*node_x + 1][node_y];
        return;
    }
    int mid_y=(st_y+en_y)/2;
    build_y(node_x, st_x, en_x, 2*node_y, st_y, mid_y);
    build_y(node_x, st_x, en_x, 2*node_y+1, mid_y+1, en_y);
    tree[node_x][node_y] = tree[node_x][2*node_y] + tree[node_x][2*node_y+1];
}

void build_x(int node_x, int st_x, int en_x, int node_y, int st_y, int en_y){
    if(st_x!=en_x){
        int mid_x=(st_x+en_x)/2;
        build_x(2*node_x, st_x, mid_x, node_y, st_y, en_y);
        build_x(2*node_x+1, mid_x+1, en_x, node_y, st_y, en_y);
    }
    build_y(node_x, st_x, en_x, node_y, st_y, en_y);
    return;   
}

int  query_y(int node_x, int node_y, int st_y, int en_y, int ly, int ry){
    if(st_y>ry || en_y<ly){return 0;}
    else if(st_y>=ly && en_y<=ry){
        return tree[node_x][node_y];
    }
    int mid_y=(st_y+en_y)/2;
    int q1= query_y(node_x, 2*node_y, st_y, mid_y, ly, ry);
    int q2= query_y(node_x, 2*node_y+1, mid_y+ 1, en_y, ly, ry);
    return q1+q2;
}

int query_x(int node_x, int st_x, int en_x, int lx, int rx, int node_y, int st_y, int en_y, int ly, int ry){
    if(st_x>rx|| en_x<lx){return 0;}
    else if(st_x>=lx && en_x<=rx){
        return query_y(node_x, node_y, st_y, en_y, ly, ry);
    }
    int mid_x=(st_x+en_x)/2;
    int q1= query_x(2*node_x, st_x, mid_x, lx, rx, node_y, st_y, en_y, ly, ry);
    int q2= query_x(2*node_x+1, mid_x+1, en_x, lx, rx, node_y, st_y, en_y, ly, ry);
    return q1+q2;
}

void update_y(int node_x, int st_x, int en_x, int node_y, int st_y, int en_y, int x, int y, int val){
    if(st_x==en_x && st_y==en_y){
        tree[node_x][node_y]=val;       arr[st_x][st_y]=val;
        return;
    }
    if(st_y==en_y){
        tree[node_x][node_y] = tree[2*node_x][node_y] + tree[2*node_x+1][node_y];
        return;
    }
    int mid_y=(st_y+en_y)/2;
    if(y<=mid_y){update_y(node_x, st_x, en_x, 2*node_y, st_y, mid_y, x, y, val);}
    else{    update_y(node_x, st_x, en_x, 2*node_y+1, mid_y+1, en_y, x, y, val);}
    tree[node_x][node_y] = tree[node_x][2*node_y] + tree[node_x][2*node_y+1];
}

void update_x(int node_x, int st_x, int en_x, int node_y, int st_y, int en_y, int x, int y, int val){
    if(st_x!=en_x){
        int mid_x=(st_x+en_x)/2;
        if(x<=mid_x){update_x(2*node_x, st_x, mid_x, node_y, st_y, en_y, x, y, val);}
        else{    update_x(2*node_x+1, mid_x+1, en_x, node_y, st_y, en_y, x, y, val);}
    }
    update_y(node_x, st_x, en_x, node_y, st_y, en_y, x, y, val);
}