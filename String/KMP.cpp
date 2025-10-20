///KMP          //KMP           //KMP           //KMP           //KMP

//const int N=1e6+6;
int lps[N];     //need 0 to n-1 indexces

void build_lps(string &pat) {
    int sz=pat.size();  
    for(int i=1; i<sz; i++){
        int k=lps[i - 1];
        while((k>0) && (pat[i] != pat[k])){k=lps[k-1];}
        if(pat[i]==pat[k]){k++;}
        lps[i]=k;
    }
return;
}

int kmp(string &txt, string &pat) {
    int sz_a=txt.size(), sz_b=pat.size();
    int ans=0;
    int k=0;
    for(int i=0; i<sz_a; i++){
        while((k>0) && (txt[i]!=pat[k])){k=lps[k-1];}
        if(txt[i]==pat[k]){k++;}
        if(k==sz_b){
            ans++;
            k=lps[k-1];
        }
    }
    return ans;
}

/*
int kmp(string &txt, string &pat){
    string s = pat + '#' + txt;
    build_lps(s);
    int sz=s.size();
    int ans=0;
    for(int i=0; i<sz; i++){
        if(lps[i]==pat.size()){ans++;}
    }
    return ans;
}
*/