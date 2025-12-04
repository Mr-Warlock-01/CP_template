//KMP automation
int aut[N][26];

vector<int>build_lps(string pat){
    int sz=pat.size(); 
    vector<int>lps(sz); 
    for(int i=1; i<sz; i++){
        int k=lps[i - 1];
        while((k>0) && (pat[i] != pat[k])){k=lps[k-1];}
        if(pat[i]==pat[k]){k++;}
        lps[i]=k;
    }
    return lps;
}

void KMP_automation(string s){
    s += '#';
    int sz=s.size();
    vector<int>pi=build_lps(s);
    for(int i=0; i<sz; i++) {
        for(int c=0; c<26; c++) {
            if(i>0 && ('a'+c)!=s[i]){
                aut[i][c]=aut[pi[i-1]][c];
            }
            else{
                aut[i][c]= i +(('a'+c)==s[i]);
            }
        }
    }
}

//kmp automation indicates -> k prefix match er por 'x' char bosaile new k koto

// aut size shuild be ---> pat.size()+1 *  26