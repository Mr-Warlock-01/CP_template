//Binary Index Tree
int BIT[2][N];

int sum(int cs, int indx){
    int ans = 0;
    while(indx!=0){
        ans+=BIT[cs][indx];
        indx-=(indx & -indx);
    }
    return ans;
}

void update(int cs, int indx, int val){
    while(indx < N){
        BIT[cs][indx]+=val;
        indx+=(indx & -indx);
    }
}

int sumRange(int indx){
    return sum(0,indx)*indx - sum(1,indx);
}

int QueryRange(int l, int r) {
    return sumRange(r)-sumRange(l-1);
}

void updateRange(int l, int r, int val){
    update(0,l,val);       
    update(0,r+1,-val);
    update(1,l,val*(l-1)); 
    update(1,r+1,-val*r);
}



const int LOGN = 20;
int LowerBound(int cs, int v){
    int sum = 0;
    int indx = 0;
    for(int i = LOGN; i >= 0; i--){
        int nPos = indx + (1<<i);
        if(nPos < MAXN && sum + BIT[cs][nPos] < v){
            sum += BIT[cs][nPos];
            indx = nPos;
        }
    }
    //pos = maximal x such that Sum(x) < v
    return indx + 1; //+1 for LowerBound
}