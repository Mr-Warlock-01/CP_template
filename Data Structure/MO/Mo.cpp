///Mo's Algorithm			//Mo's Algorithm			//Mo's Algorithm			//Mo's Algorithm

//const int N=100;
//const int block_sz = sqrt(N);

const int block_sz=316; //if N=1e5
pair<pair<int,int>,int>v[N]; // ((l,r),idx)


bool mo_sort(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
    if((a.ff.ff/block_sz)!=(b.ff.ff/block_sz)){return (a.ff.ff < b.ff.ff);}
    else{
        if((a.ff.ff/block_sz) & 1){return (a.ff.ss > b.ff.ss);}
        return (a.ff.ss < b.ff.ss);
    }
}

//int main function
//sort(v, v+q, mo_sort);

int cur_l = 0;
int cur_r = -1;

//   l <<<
//   r >>>
//   l >>>
//   r <<<

/*
    for(int i=0; i<q; i++){
        int need_l = v[i].ff.ff;
        int need_r = v[i].ff.ss;
        int indx   = v[i].ss;

        while(cur_l>need_l){
            cur_l--;
            l_add(cur_l);
        }
        while(cur_r<need_r){
            cur_r++;
            r_add(cur_r);
        }
        while(cur_l<need_l){
            l_remove(cur_l);
            cur_l++;
        }
        while(cur_r>need_r){
            r_remove(cur_r);
            cur_r--;
        }
        ans[indx]=res;
    }
    */

