///Manachar Algorithm

int p[N];      //need first 2N+1 index
//vector<int>p((2*N)+1);

void manacher(string &s){
    string temp="#";
    for(auto u : s) {
        temp.pb(u);
        temp.pb('#');
    }

    int nn = temp.length();
    int l=0, r=-1;
    for(int i=0; i<nn;i++){
        int k=0;
        if(i<=r){k = min(p[l+r-i], r-i);}
        while(((i+k+1)<nn) && ((i-k-1)>=0) && (temp[i+k+1]==temp[i-1-k])){k++;}
        p[i]=k;
        if((i+k)>r){
            r=i+k;
            l=i-k;
        }
    }
}

