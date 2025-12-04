//MO with update
const int N=1e5+7;
const int block_sz=2200;   // n/cbrt(n); (2*n*n)^(1/3) works better

ll L=0,R=-1;

struct query{
    int l,r,t,idx;
    query(){}
    query(int l, int r, int t, int idx):l(l),r(r),t(t),idx(idx){}
    bool operator<(const query &q)const{
        int curl=l/block_sz, otherl = q.l/block_sz;
        int curr=r/block_sz, otherr = q.r/block_sz;
        if(curl^otherl){return curl<otherl;}
        if(curr^otherr){return curr<otherr;}
        return t<q.t;
    }
}queries[N];

struct update{
    int ind;
    int prev,nxt; 
    update(){}
    update(int ind,int prev,int nxt):ind(ind),prev(prev),nxt(nxt){}
}updates[N];


void add(int idx){
    int val=arr[idx];
    freq[cnt[val]]--;
    cnt[val]++;
    freq[cnt[val]]++;
}

void remove(int idx){
    int val=arr[idx];
    freq[cnt[val]]--;
    cnt[val]--;
    freq[cnt[val]]++;
}

void adjust(ll idx, int val){
    if((L<=idx) && (idx<=R)){
        remove(idx);
        arr[idx]=val;
        add(idx);
    }
    else{
        arr[idx]=val;
    }
}



//main_function

/*
	int updateCnt=0;
    int queryCnt=0;

	for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){//query
        	int l,r; cin>>l>>r;
            queries[queryCnt]=query(l,r,updateCnt,queryCnt);
            queryCnt++;
        }
        else{//update
            int idx,val;    cin>>idx>>val;
            updates[updateCnt++]=update(idx,arr[idx],val);
            arr[idx]=val;
        }
    }


    sort(queries,queries+queryCnt);
    for(int i=0;i<queryCnt;i++){
        while(L>queries[i].l){add(--L);}
        while(R<queries[i].r){add(++R);}
        while(L<queries[i].l){remove(L++);}
        while(R>queries[i].r){remove(R--);}

        while(updateCnt<queries[i].t){
            adjust(updates[updateCnt].ind,updates[updateCnt].nxt);
            updateCnt++;
        }
        while(updateCnt>queries[i].t){
            updateCnt--;
            adjust(updates[updateCnt].ind,updates[updateCnt].prev);
        }
        int res=1;
        while(freq[res]>0){res++;}
        ans[queries[i].idx]=res;
    }
*/